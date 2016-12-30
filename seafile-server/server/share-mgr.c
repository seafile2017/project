/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#include "common.h"
#include "utils.h"

#include "log.h"

#include "seafile-session.h"
#include "share-mgr.h"

#include "seaf-db.h"
#include "log.h"
#include "seafile-error.h"

SeafShareManager *
seaf_share_manager_new (SeafileSession *seaf)
{
    SeafShareManager *mgr = g_new0 (SeafShareManager, 1);

    mgr->seaf = seaf;

    return mgr;
}

int
seaf_share_manager_start (SeafShareManager *mgr)
{
    SeafDB *db = mgr->seaf->db;
    const char *sql;

    int db_type = seaf_db_type (db);
    if (db_type == SEAF_DB_TYPE_MYSQL) {
        sql = "CREATE TABLE IF NOT EXISTS SharedRepo "
            "(id INTEGER NOT NULL PRIMARY KEY AUTO_INCREMENT,"
            "repo_id CHAR(37) , from_email VARCHAR(255), to_email VARCHAR(255), "
            "permission CHAR(15), INDEX (repo_id), "
            "INDEX(from_email), INDEX(to_email)) ENGINE=INNODB";

        if (seaf_db_query (db, sql) < 0)
            return -1;
    } else if (db_type == SEAF_DB_TYPE_SQLITE) {
        sql = "CREATE TABLE IF NOT EXISTS SharedRepo "
            "(repo_id CHAR(37) , from_email VARCHAR(255), to_email VARCHAR(255), "
            "permission CHAR(15))";
        if (seaf_db_query (db, sql) < 0)
            return -1;
        sql = "CREATE INDEX IF NOT EXISTS RepoIdIndex on SharedRepo (repo_id)";
        if (seaf_db_query (db, sql) < 0)
            return -1;
        sql = "CREATE INDEX IF NOT EXISTS FromEmailIndex on SharedRepo (from_email)";
        if (seaf_db_query (db, sql) < 0)
            return -1;
        sql = "CREATE INDEX IF NOT EXISTS ToEmailIndex on SharedRepo (to_email)";
        if (seaf_db_query (db, sql) < 0)
            return -1;
    } else if (db_type == SEAF_DB_TYPE_PGSQL) {
        sql = "CREATE TABLE IF NOT EXISTS SharedRepo "
            "(repo_id CHAR(36) , from_email VARCHAR(255), to_email VARCHAR(255), "
            "permission VARCHAR(15))";
        if (seaf_db_query (db, sql) < 0)
            return -1;

        if (!pgsql_index_exists (db, "sharedrepo_repoid_idx")) {
            sql = "CREATE INDEX sharedrepo_repoid_idx ON SharedRepo (repo_id)";
            if (seaf_db_query (db, sql) < 0)
                return -1;
        }
        if (!pgsql_index_exists (db, "sharedrepo_from_email_idx")) {
            sql = "CREATE INDEX sharedrepo_from_email_idx ON SharedRepo (from_email)";
            if (seaf_db_query (db, sql) < 0)
                return -1;
        }
        if (!pgsql_index_exists (db, "sharedrepo_to_email_idx")) {
            sql = "CREATE INDEX sharedrepo_to_email_idx ON SharedRepo (to_email)";
            if (seaf_db_query (db, sql) < 0)
                return -1;
        }
    }
    
    return 0;
}

int
seaf_share_manager_add_share (SeafShareManager *mgr, const char *repo_id,
                              const char *from_email, const char *to_email,
                              const char *permission)
{
    gboolean db_err = FALSE;
    int ret = 0;

    char *from_email_l = g_ascii_strdown (from_email, -1);
    char *to_email_l = g_ascii_strdown (to_email, -1);

    if (seaf_db_statement_exists (mgr->seaf->db,
                                  "SELECT repo_id from SharedRepo "
                                  "WHERE repo_id=? AND "
                                  "from_email=? AND to_email=?",
                                  &db_err, 3, "string", repo_id,
                                  "string", from_email_l, "string", to_email_l))
        goto out;

    if (seaf_db_statement_query (mgr->seaf->db,
                                 "INSERT INTO SharedRepo (repo_id, from_email, "
                                 "to_email, permission) VALUES (?, ?, ?, ?)",
                                 4, "string", repo_id, "string", from_email_l,
                                 "string", to_email_l, "string", permission) < 0) {
        ret = -1;
        goto out;
    }

out:
    g_free (from_email_l);
    g_free (to_email_l);
    return ret;
}

int
seaf_share_manager_set_permission (SeafShareManager *mgr, const char *repo_id,
                                   const char *from_email, const char *to_email,
                                   const char *permission)
{
    char *sql;
    int ret;

    char *from_email_l = g_ascii_strdown (from_email, -1);
    char *to_email_l = g_ascii_strdown (to_email, -1);
    sql = "UPDATE SharedRepo SET permission=? WHERE "
        "repo_id=? AND from_email=? AND to_email=?";

    ret = seaf_db_statement_query (mgr->seaf->db, sql,
                                   4, "string", permission, "string", repo_id,
                                   "string", from_email_l, "string", to_email_l);

    g_free (from_email_l);
    g_free (to_email_l);
    return ret;
}

static gboolean
collect_repos (SeafDBRow *row, void *data)
{
    GList **p_repos = data;
    const char *repo_id;
    const char *vrepo_id;
    const char *email;
    const char *permission;
    const char *commit_id;
    gint64 size;
    SeafileRepo *repo;

    repo_id = seaf_db_row_get_column_text (row, 0);
    vrepo_id = seaf_db_row_get_column_text (row, 1);
    email = seaf_db_row_get_column_text (row, 2);
    permission = seaf_db_row_get_column_text (row, 3);
    commit_id = seaf_db_row_get_column_text (row, 4);
    size = seaf_db_row_get_column_int64 (row, 5);

    char *email_l = g_ascii_strdown (email, -1);

    repo = g_object_new (SEAFILE_TYPE_REPO,
                         "share_type", "personal",
                         "repo_id", repo_id,
                         "id", repo_id,
                         "head_cmmt_id", commit_id,
                         "user", email_l,
                         "permission", permission,
                         "is_virtual", (vrepo_id != NULL),
                         "size", size,
                         NULL);
    g_free (email_l);

    if (repo) {
        if (vrepo_id) {
            const char *origin_repo_id = seaf_db_row_get_column_text (row, 6);
            const char *origin_path = seaf_db_row_get_column_text (row, 7);
            g_object_set (repo, "store_id", origin_repo_id,
                          "origin_repo_id", origin_repo_id,
                          "origin_path", origin_path, NULL);
        } else {
            g_object_set (repo, "store_id", repo_id, NULL);
        }
        *p_repos = g_list_prepend (*p_repos, repo);
    }

    return TRUE;
}

GList*
seaf_share_manager_list_share_repos (SeafShareManager *mgr, const char *email,
                                     const char *type, int start, int limit)
{
    GList *ret = NULL, *p;
    char *sql;

    if (start == -1 && limit == -1) {
        if (g_strcmp0 (type, "from_email") == 0) {
            sql = "SELECT SharedRepo.repo_id, VirtualRepo.repo_id, "
                "to_email, permission, commit_id, s.size, "
                "VirtualRepo.origin_repo, VirtualRepo.path FROM "
                "SharedRepo LEFT JOIN VirtualRepo ON "
                "SharedRepo.repo_id=VirtualRepo.repo_id "
                "LEFT JOIN RepoSize s ON SharedRepo.repo_id = s.repo_id, Branch "
                "WHERE from_email=? AND "
                "SharedRepo.repo_id = Branch.repo_id AND "
                "Branch.name = 'master'";
        } else if (g_strcmp0 (type, "to_email") == 0) {
            sql = "SELECT SharedRepo.repo_id, VirtualRepo.repo_id, "
                "from_email, permission, commit_id, s.size, "
                "VirtualRepo.origin_repo, VirtualRepo.path FROM "
                "SharedRepo LEFT JOIN VirtualRepo on SharedRepo.repo_id = VirtualRepo.repo_id "
                "LEFT JOIN RepoSize s ON SharedRepo.repo_id = s.repo_id, Branch "
                "WHERE to_email=? AND "
                "SharedRepo.repo_id = Branch.repo_id AND "
                "Branch.name = 'master'";
        } else {
            /* should never reach here */
            seaf_warning ("[share mgr] Wrong column type");
            return NULL;
        }

        if (seaf_db_statement_foreach_row (mgr->seaf->db, sql,
                                           collect_repos, &ret,
                                           1, "string", email) < 0) {
            seaf_warning ("[share mgr] DB error when get shared repo id and email "
                       "for %s.\n", email);
            for (p = ret; p; p = p->next)
                g_object_unref (p->data);
            g_list_free (ret);
            return NULL;
        }
    }
    else {
        if (g_strcmp0 (type, "from_email") == 0) {
            sql = "SELECT SharedRepo.repo_id, VirtualRepo.repo_id, "
                "to_email, permission, commit_id, s.size, "
                "VirtualRepo.origin_repo, VirtualRepo.path FROM "
                "SharedRepo LEFT JOIN VirtualRepo ON "
                "SharedRepo.repo_id=VirtualRepo.repo_id "
                "LEFT JOIN RepoSize s ON SharedRepo.repo_id = s.repo_id, Branch "
                "WHERE from_email=? "
                "AND SharedRepo.repo_id = Branch.repo_id "
                "AND Branch.name = 'master' "
                "ORDER BY SharedRepo.repo_id "
                "LIMIT ? OFFSET ?";
        } else if (g_strcmp0 (type, "to_email") == 0) {
            sql = "SELECT SharedRepo.repo_id, VirtualRepo.repo_id, "
                "from_email, permission, commit_id, s.size, "
                "VirtualRepo.origin_repo, VirtualRepo.path FROM "
                "SharedRepo LEFT JOIN VirtualRepo on SharedRepo.repo_id = VirtualRepo.repo_id "
                "LEFT JOIN RepoSize s ON SharedRepo.repo_id = s.repo_id, "
                "Branch WHERE to_email=? "
                "AND SharedRepo.repo_id = Branch.repo_id "
                "AND Branch.name = 'master' "
                "ORDER BY SharedRepo.repo_id "
                "LIMIT ? OFFSET ?";
        } else {
            /* should never reach here */
            seaf_warning ("[share mgr] Wrong column type");
            return NULL;
        }

        if (seaf_db_statement_foreach_row (mgr->seaf->db, sql,
                                           collect_repos, &ret,
                                           3, "string", email,
                                           "int", limit, "int", start) < 0) {
            seaf_warning ("[share mgr] DB error when get shared repo id and email "
                       "for %s.\n", email);
            for (p = ret; p; p = p->next)
                g_object_unref (p->data);
            g_list_free (ret);
            return NULL;
        }
    }

    seaf_fill_repo_obj_from_commit (&ret);

    return g_list_reverse (ret);
}

static gboolean
collect_shared_to (SeafDBRow *row, void *data)
{
    GList **plist = data;
    const char *to_email;

    to_email = seaf_db_row_get_column_text (row, 0);
    *plist = g_list_prepend (*plist, g_ascii_strdown(to_email, -1));

    return TRUE;
}

GList *
seaf_share_manager_list_shared_to (SeafShareManager *mgr,
                                   const char *owner,
                                   const char *repo_id)
{
    char *sql;
    GList *ret = NULL;

    sql = "SELECT to_email FROM SharedRepo WHERE "
        "from_email=? AND repo_id=?";
    if (seaf_db_statement_foreach_row (mgr->seaf->db, sql,
                                       collect_shared_to, &ret,
                                       2, "string", owner, "string", repo_id) < 0) {
        seaf_warning ("[share mgr] DB error when list shared to.\n");
        string_list_free (ret);
        return NULL;
    }

    return ret;
}

static gboolean
collect_repo_shared_to (SeafDBRow *row, void *data)
{
    GList **shared_to = data;
    const char *to_email = seaf_db_row_get_column_text (row, 0);
    char *email_down = g_ascii_strdown(to_email, -1);
    const char *perm = seaf_db_row_get_column_text (row, 1);
    const char *repo_id = seaf_db_row_get_column_text (row, 2);

    SeafileSharedUser *uobj = g_object_new (SEAFILE_TYPE_SHARED_USER,
                                            "repo_id", repo_id,
                                            "user", email_down,
                                            "perm", perm,
                                            NULL);
    *shared_to = g_list_prepend (*shared_to, uobj);
    g_free (email_down);

    return TRUE;
}

GList *
seaf_share_manager_list_repo_shared_to (SeafShareManager *mgr,
                                        const char *from_email,
                                        const char *repo_id,
                                        GError **error)
{
    GList *shared_to = NULL;
    char *sql = "SELECT to_email, permission, repo_id FROM SharedRepo WHERE "
                "from_email=? AND repo_id=?";

    int ret = seaf_db_statement_foreach_row (mgr->seaf->db, sql,
                                             collect_repo_shared_to, &shared_to,
                                             2, "string", from_email, "string", repo_id);
    if (ret < 0) {
        seaf_warning ("Failed to list repo %s shared to from db.\n", repo_id);
        g_set_error (error, SEAFILE_DOMAIN, SEAF_ERR_GENERAL,
                     "Failed to list repo shared to from db");
        while (shared_to) {
            g_object_unref (shared_to->data);
            shared_to = g_list_delete_link (shared_to, shared_to);
        }
        return NULL;
    }

    return shared_to;
}

static gboolean
collect_repo_shared_group (SeafDBRow *row, void *data)
{
    GList **shared_group = data;
    int group_id = seaf_db_row_get_column_int (row, 0);
    const char *perm = seaf_db_row_get_column_text (row, 1);
    const char *repo_id = seaf_db_row_get_column_text (row, 2);

    SeafileSharedGroup *gobj = g_object_new (SEAFILE_TYPE_SHARED_GROUP,
                                             "repo_id", repo_id,
                                             "group_id", group_id,
                                             "perm", perm,
                                             NULL);
    *shared_group = g_list_prepend (*shared_group, gobj);

    return TRUE;
}

GList *
seaf_share_manager_list_repo_shared_group (SeafShareManager *mgr,
                                           const char *from_email,
                                           const char *repo_id,
                                           GError **error)
{
    GList *shared_group = NULL;
    char *sql = "SELECT group_id, permission, repo_id FROM RepoGroup WHERE "
                "user_name=? AND repo_id=?";

    int ret = seaf_db_statement_foreach_row (mgr->seaf->db, sql,
                                             collect_repo_shared_group, &shared_group,
                                             2, "string", from_email, "string", repo_id);
    if (ret < 0) {
        seaf_warning ("Failed to list repo %s shared group from db.\n", repo_id);
        g_set_error (error, SEAFILE_DOMAIN, SEAF_ERR_GENERAL,
                     "Failed to list repo shared group from db");
        while (shared_group) {
            g_object_unref (shared_group->data);
            shared_group = g_list_delete_link (shared_group, shared_group);
        }
        return NULL;
    }

    return shared_group;
}

int
seaf_share_manager_remove_share (SeafShareManager *mgr, const char *repo_id,
                                 const char *from_email, const char *to_email)
{
    if (seaf_db_statement_query (mgr->seaf->db,
                       "DELETE FROM SharedRepo WHERE repo_id = ? AND from_email ="
                       " ? AND to_email = ?",
                       3, "string", repo_id, "string", from_email,
                       "string", to_email) < 0)
        return -1;

    return 0;
}

int
seaf_share_manager_remove_repo (SeafShareManager *mgr, const char *repo_id)
{
    if (seaf_db_statement_query (mgr->seaf->db,
                       "DELETE FROM SharedRepo WHERE repo_id = ?",
                       1, "string", repo_id) < 0)
        return -1;

    return 0;
}

char *
seaf_share_manager_check_permission (SeafShareManager *mgr,
                                     const char *repo_id,
                                     const char *email)
{
    char *sql;

    sql = "SELECT permission FROM SharedRepo WHERE repo_id=? AND to_email=?";
    return seaf_db_statement_get_string (mgr->seaf->db, sql,
                                         2, "string", repo_id, "string", email);
}

static gboolean
get_shared_sub_dirs (SeafDBRow *row, void *data)
{
    GHashTable *sub_dirs = data;
    int dummy;

    const char *sub_dir = seaf_db_row_get_column_text (row, 0);
    g_hash_table_replace (sub_dirs, g_strdup(sub_dir), &dummy);

    return TRUE;
}

GHashTable *
seaf_share_manager_get_shared_sub_dirs (SeafShareManager *mgr,
                                        const char *repo_id,
                                        const char *path)
{
    GHashTable *sub_dirs = g_hash_table_new_full (g_str_hash, g_str_equal,
                                                  g_free, NULL);
    char *pattern;
    if (strcmp (path, "/") == 0) {
        pattern = g_strdup_printf("%s%%", path);
    } else {
        pattern = g_strdup_printf ("%s/%%", path);
    }
    int ret = seaf_db_statement_foreach_row (mgr->seaf->db,
                                             "SELECT v.path FROM VirtualRepo v, SharedRepo s "
                                             "WHERE v.repo_id = s.repo_id and "
                                             "v.origin_repo = ? AND v.path LIKE ?",
                                             get_shared_sub_dirs, sub_dirs,
                                             2, "string", repo_id, "string", pattern);

    if (ret < 0) {
        g_free (pattern);
        seaf_warning ("Failed to get shared sub dirs from db.\n");
        g_hash_table_destroy (sub_dirs);
        return NULL;
    }

    ret = seaf_db_statement_foreach_row (mgr->seaf->db,
                                         "SELECT v.path FROM VirtualRepo v, RepoGroup r "
                                         "WHERE v.repo_id = r.repo_id and "
                                         "v.origin_repo = ? AND v.path LIKE ?",
                                         get_shared_sub_dirs, sub_dirs,
                                         2, "string", repo_id, "string", pattern);
    g_free (pattern);

    if (ret < 0) {
        seaf_warning ("Failed to get shared sub dirs from db.\n");
        g_hash_table_destroy (sub_dirs);
        return NULL;
    }

    return sub_dirs;
}

int
seaf_share_manager_is_repo_shared (SeafShareManager *mgr,
                                   const char *repo_id)
{
    gboolean ret;
    gboolean db_err = FALSE;

    ret = seaf_db_statement_exists (mgr->seaf->db,
                                    "SELECT repo_id FROM SharedRepo WHERE "
                                    "repo_id = ?", &db_err,
                                    1, "string", repo_id);
    if (db_err) {
        seaf_warning ("DB error when check repo exist in SharedRepo.\n");
        return -1;
    }

    if (!ret) {
        ret = seaf_db_statement_exists (mgr->seaf->db,
                                        "SELECT repo_id FROM RepoGroup WHERE "
                                        "repo_id = ?", &db_err,
                                        1, "string", repo_id);
        if (db_err) {
            seaf_warning ("DB error when check repo exist in RepoGroup.\n");
            return -1;
        }
    }

    return ret;
}

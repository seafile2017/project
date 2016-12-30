/* dir.c generated by valac 0.34.4, the Vala compiler
 * generated from dir.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <string.h>


#define SEAFILE_TYPE_DIR (seafile_dir_get_type ())
#define SEAFILE_DIR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SEAFILE_TYPE_DIR, SeafileDir))
#define SEAFILE_DIR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SEAFILE_TYPE_DIR, SeafileDirClass))
#define SEAFILE_IS_DIR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SEAFILE_TYPE_DIR))
#define SEAFILE_IS_DIR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SEAFILE_TYPE_DIR))
#define SEAFILE_DIR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SEAFILE_TYPE_DIR, SeafileDirClass))

typedef struct _SeafileDir SeafileDir;
typedef struct _SeafileDirClass SeafileDirClass;
typedef struct _SeafileDirPrivate SeafileDirPrivate;

#define SEAFILE_TYPE_DIRENT (seafile_dirent_get_type ())
#define SEAFILE_DIRENT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SEAFILE_TYPE_DIRENT, SeafileDirent))
#define SEAFILE_DIRENT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SEAFILE_TYPE_DIRENT, SeafileDirentClass))
#define SEAFILE_IS_DIRENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SEAFILE_TYPE_DIRENT))
#define SEAFILE_IS_DIRENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SEAFILE_TYPE_DIRENT))
#define SEAFILE_DIRENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SEAFILE_TYPE_DIRENT, SeafileDirentClass))

typedef struct _SeafileDirent SeafileDirent;
typedef struct _SeafileDirentClass SeafileDirentClass;
#define __g_list_free__g_object_unref0_0(var) ((var == NULL) ? NULL : (var = (_g_list_free__g_object_unref0_ (var), NULL)))

struct _SeafileDir {
	GObject parent_instance;
	SeafileDirPrivate * priv;
	gchar _id[41];
	GList* entries;
};

struct _SeafileDirClass {
	GObjectClass parent_class;
};

struct _SeafileDirPrivate {
	gint _version;
};


static gpointer seafile_dir_parent_class = NULL;

GType seafile_dir_get_type (void) G_GNUC_CONST;
GType seafile_dirent_get_type (void) G_GNUC_CONST;
#define SEAFILE_DIR_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), SEAFILE_TYPE_DIR, SeafileDirPrivate))
enum  {
	SEAFILE_DIR_DUMMY_PROPERTY,
	SEAFILE_DIR_ID,
	SEAFILE_DIR_VERSION
};
static void _g_object_unref0_ (gpointer var);
static void _g_list_free__g_object_unref0_ (GList* self);
SeafileDir* seafile_dir_new (void);
SeafileDir* seafile_dir_construct (GType object_type);
const gchar* seafile_dir_get_id (SeafileDir* self);
void seafile_dir_set_id (SeafileDir* self, const gchar* value);
gint seafile_dir_get_version (SeafileDir* self);
void seafile_dir_set_version (SeafileDir* self, gint value);
static void seafile_dir_finalize (GObject* obj);
static void _vala_seafile_dir_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_seafile_dir_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


static void _g_object_unref0_ (gpointer var) {
	(var == NULL) ? NULL : (var = (g_object_unref (var), NULL));
}


static void _g_list_free__g_object_unref0_ (GList* self) {
	g_list_foreach (self, (GFunc) _g_object_unref0_, NULL);
	g_list_free (self);
}


SeafileDir* seafile_dir_construct (GType object_type) {
	SeafileDir * self = NULL;
	self = (SeafileDir*) g_object_new (object_type, NULL);
	return self;
}


SeafileDir* seafile_dir_new (void) {
	return seafile_dir_construct (SEAFILE_TYPE_DIR);
}


const gchar* seafile_dir_get_id (SeafileDir* self) {
	const gchar* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = (const gchar*) self->_id;
	return result;
}


void seafile_dir_set_id (SeafileDir* self, const gchar* value) {
	const gchar* _tmp0_ = NULL;
	gchar _tmp1_ = '\0';
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	memcpy (self->_id, _tmp0_, (gsize) 40);
	self->_id[40] = '\0';
	_tmp1_ = self->_id[40];
	g_object_notify ((GObject *) self, "id");
}


gint seafile_dir_get_version (SeafileDir* self) {
	gint result;
	gint _tmp0_ = 0;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->_version;
	result = _tmp0_;
	return result;
}


void seafile_dir_set_version (SeafileDir* self, gint value) {
	gint _tmp0_ = 0;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_version = _tmp0_;
	g_object_notify ((GObject *) self, "version");
}


static void seafile_dir_class_init (SeafileDirClass * klass) {
	seafile_dir_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (SeafileDirPrivate));
	G_OBJECT_CLASS (klass)->get_property = _vala_seafile_dir_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_seafile_dir_set_property;
	G_OBJECT_CLASS (klass)->finalize = seafile_dir_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), SEAFILE_DIR_ID, g_param_spec_string ("id", "id", "id", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), SEAFILE_DIR_VERSION, g_param_spec_int ("version", "version", "version", G_MININT, G_MAXINT, 0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void seafile_dir_instance_init (SeafileDir * self) {
	self->priv = SEAFILE_DIR_GET_PRIVATE (self);
}


static void seafile_dir_finalize (GObject* obj) {
	SeafileDir * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, SEAFILE_TYPE_DIR, SeafileDir);
	__g_list_free__g_object_unref0_0 (self->entries);
	G_OBJECT_CLASS (seafile_dir_parent_class)->finalize (obj);
}


GType seafile_dir_get_type (void) {
	static volatile gsize seafile_dir_type_id__volatile = 0;
	if (g_once_init_enter (&seafile_dir_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (SeafileDirClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) seafile_dir_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (SeafileDir), 0, (GInstanceInitFunc) seafile_dir_instance_init, NULL };
		GType seafile_dir_type_id;
		seafile_dir_type_id = g_type_register_static (G_TYPE_OBJECT, "SeafileDir", &g_define_type_info, 0);
		g_once_init_leave (&seafile_dir_type_id__volatile, seafile_dir_type_id);
	}
	return seafile_dir_type_id__volatile;
}


static void _vala_seafile_dir_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	SeafileDir * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, SEAFILE_TYPE_DIR, SeafileDir);
	switch (property_id) {
		case SEAFILE_DIR_ID:
		g_value_set_string (value, seafile_dir_get_id (self));
		break;
		case SEAFILE_DIR_VERSION:
		g_value_set_int (value, seafile_dir_get_version (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_seafile_dir_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	SeafileDir * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, SEAFILE_TYPE_DIR, SeafileDir);
	switch (property_id) {
		case SEAFILE_DIR_ID:
		seafile_dir_set_id (self, g_value_get_string (value));
		break;
		case SEAFILE_DIR_VERSION:
		seafile_dir_set_version (self, g_value_get_int (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




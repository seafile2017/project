
static char *
marshal_int__void (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;

    int ret = ((int (*)(GError **))func) (&error);

    json_t *object = json_object ();
    searpc_set_int_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_int__int (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    int param1 = json_array_get_int_element (param_array, 1);

    int ret = ((int (*)(int, GError **))func) (param1, &error);

    json_t *object = json_object ();
    searpc_set_int_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_int__int_int (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    int param1 = json_array_get_int_element (param_array, 1);
    int param2 = json_array_get_int_element (param_array, 2);

    int ret = ((int (*)(int, int, GError **))func) (param1, param2, &error);

    json_t *object = json_object ();
    searpc_set_int_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_int__int_string (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    int param1 = json_array_get_int_element (param_array, 1);
    const char* param2 = json_array_get_string_or_null_element (param_array, 2);

    int ret = ((int (*)(int, const char*, GError **))func) (param1, param2, &error);

    json_t *object = json_object ();
    searpc_set_int_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_int__int_string_int (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    int param1 = json_array_get_int_element (param_array, 1);
    const char* param2 = json_array_get_string_or_null_element (param_array, 2);
    int param3 = json_array_get_int_element (param_array, 3);

    int ret = ((int (*)(int, const char*, int, GError **))func) (param1, param2, param3, &error);

    json_t *object = json_object ();
    searpc_set_int_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_int__int_string_string (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    int param1 = json_array_get_int_element (param_array, 1);
    const char* param2 = json_array_get_string_or_null_element (param_array, 2);
    const char* param3 = json_array_get_string_or_null_element (param_array, 3);

    int ret = ((int (*)(int, const char*, const char*, GError **))func) (param1, param2, param3, &error);

    json_t *object = json_object ();
    searpc_set_int_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_int__int_string_int_int (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    int param1 = json_array_get_int_element (param_array, 1);
    const char* param2 = json_array_get_string_or_null_element (param_array, 2);
    int param3 = json_array_get_int_element (param_array, 3);
    int param4 = json_array_get_int_element (param_array, 4);

    int ret = ((int (*)(int, const char*, int, int, GError **))func) (param1, param2, param3, param4, &error);

    json_t *object = json_object ();
    searpc_set_int_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_int__string (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);

    int ret = ((int (*)(const char*, GError **))func) (param1, &error);

    json_t *object = json_object ();
    searpc_set_int_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_int__string_int (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);
    int param2 = json_array_get_int_element (param_array, 2);

    int ret = ((int (*)(const char*, int, GError **))func) (param1, param2, &error);

    json_t *object = json_object ();
    searpc_set_int_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_int__string_int_string (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);
    int param2 = json_array_get_int_element (param_array, 2);
    const char* param3 = json_array_get_string_or_null_element (param_array, 3);

    int ret = ((int (*)(const char*, int, const char*, GError **))func) (param1, param2, param3, &error);

    json_t *object = json_object ();
    searpc_set_int_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_int__string_int_string_string (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);
    int param2 = json_array_get_int_element (param_array, 2);
    const char* param3 = json_array_get_string_or_null_element (param_array, 3);
    const char* param4 = json_array_get_string_or_null_element (param_array, 4);

    int ret = ((int (*)(const char*, int, const char*, const char*, GError **))func) (param1, param2, param3, param4, &error);

    json_t *object = json_object ();
    searpc_set_int_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_int__string_int_string_int_int (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);
    int param2 = json_array_get_int_element (param_array, 2);
    const char* param3 = json_array_get_string_or_null_element (param_array, 3);
    int param4 = json_array_get_int_element (param_array, 4);
    int param5 = json_array_get_int_element (param_array, 5);

    int ret = ((int (*)(const char*, int, const char*, int, int, GError **))func) (param1, param2, param3, param4, param5, &error);

    json_t *object = json_object ();
    searpc_set_int_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_int__string_string (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);
    const char* param2 = json_array_get_string_or_null_element (param_array, 2);

    int ret = ((int (*)(const char*, const char*, GError **))func) (param1, param2, &error);

    json_t *object = json_object ();
    searpc_set_int_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_int__string_string_string (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);
    const char* param2 = json_array_get_string_or_null_element (param_array, 2);
    const char* param3 = json_array_get_string_or_null_element (param_array, 3);

    int ret = ((int (*)(const char*, const char*, const char*, GError **))func) (param1, param2, param3, &error);

    json_t *object = json_object ();
    searpc_set_int_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_int__string_string_int (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);
    const char* param2 = json_array_get_string_or_null_element (param_array, 2);
    int param3 = json_array_get_int_element (param_array, 3);

    int ret = ((int (*)(const char*, const char*, int, GError **))func) (param1, param2, param3, &error);

    json_t *object = json_object ();
    searpc_set_int_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_int__string_string_int_int (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);
    const char* param2 = json_array_get_string_or_null_element (param_array, 2);
    int param3 = json_array_get_int_element (param_array, 3);
    int param4 = json_array_get_int_element (param_array, 4);

    int ret = ((int (*)(const char*, const char*, int, int, GError **))func) (param1, param2, param3, param4, &error);

    json_t *object = json_object ();
    searpc_set_int_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_int__string_string_string_string (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);
    const char* param2 = json_array_get_string_or_null_element (param_array, 2);
    const char* param3 = json_array_get_string_or_null_element (param_array, 3);
    const char* param4 = json_array_get_string_or_null_element (param_array, 4);

    int ret = ((int (*)(const char*, const char*, const char*, const char*, GError **))func) (param1, param2, param3, param4, &error);

    json_t *object = json_object ();
    searpc_set_int_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_int__string_string_string_string_string (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);
    const char* param2 = json_array_get_string_or_null_element (param_array, 2);
    const char* param3 = json_array_get_string_or_null_element (param_array, 3);
    const char* param4 = json_array_get_string_or_null_element (param_array, 4);
    const char* param5 = json_array_get_string_or_null_element (param_array, 5);

    int ret = ((int (*)(const char*, const char*, const char*, const char*, const char*, GError **))func) (param1, param2, param3, param4, param5, &error);

    json_t *object = json_object ();
    searpc_set_int_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_int__string_string_string_string_string_string (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);
    const char* param2 = json_array_get_string_or_null_element (param_array, 2);
    const char* param3 = json_array_get_string_or_null_element (param_array, 3);
    const char* param4 = json_array_get_string_or_null_element (param_array, 4);
    const char* param5 = json_array_get_string_or_null_element (param_array, 5);
    const char* param6 = json_array_get_string_or_null_element (param_array, 6);

    int ret = ((int (*)(const char*, const char*, const char*, const char*, const char*, const char*, GError **))func) (param1, param2, param3, param4, param5, param6, &error);

    json_t *object = json_object ();
    searpc_set_int_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_int__string_string_string_string_string_string_string (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);
    const char* param2 = json_array_get_string_or_null_element (param_array, 2);
    const char* param3 = json_array_get_string_or_null_element (param_array, 3);
    const char* param4 = json_array_get_string_or_null_element (param_array, 4);
    const char* param5 = json_array_get_string_or_null_element (param_array, 5);
    const char* param6 = json_array_get_string_or_null_element (param_array, 6);
    const char* param7 = json_array_get_string_or_null_element (param_array, 7);

    int ret = ((int (*)(const char*, const char*, const char*, const char*, const char*, const char*, const char*, GError **))func) (param1, param2, param3, param4, param5, param6, param7, &error);

    json_t *object = json_object ();
    searpc_set_int_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_int__string_int64 (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);
    gint64 param2 = json_array_get_int_element (param_array, 2);

    int ret = ((int (*)(const char*, gint64, GError **))func) (param1, param2, &error);

    json_t *object = json_object ();
    searpc_set_int_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_int__int_int64 (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    int param1 = json_array_get_int_element (param_array, 1);
    gint64 param2 = json_array_get_int_element (param_array, 2);

    int ret = ((int (*)(int, gint64, GError **))func) (param1, param2, &error);

    json_t *object = json_object ();
    searpc_set_int_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_int__int_string_int64 (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    int param1 = json_array_get_int_element (param_array, 1);
    const char* param2 = json_array_get_string_or_null_element (param_array, 2);
    gint64 param3 = json_array_get_int_element (param_array, 3);

    int ret = ((int (*)(int, const char*, gint64, GError **))func) (param1, param2, param3, &error);

    json_t *object = json_object ();
    searpc_set_int_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_int64__void (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;

    gint64 ret = ((gint64 (*)(GError **))func) (&error);

    json_t *object = json_object ();
    searpc_set_int_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_int64__string (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);

    gint64 ret = ((gint64 (*)(const char*, GError **))func) (param1, &error);

    json_t *object = json_object ();
    searpc_set_int_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_int64__int (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    int param1 = json_array_get_int_element (param_array, 1);

    gint64 ret = ((gint64 (*)(int, GError **))func) (param1, &error);

    json_t *object = json_object ();
    searpc_set_int_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_int64__int_string (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    int param1 = json_array_get_int_element (param_array, 1);
    const char* param2 = json_array_get_string_or_null_element (param_array, 2);

    gint64 ret = ((gint64 (*)(int, const char*, GError **))func) (param1, param2, &error);

    json_t *object = json_object ();
    searpc_set_int_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_string__void (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;

    char* ret = ((char* (*)(GError **))func) (&error);

    json_t *object = json_object ();
    searpc_set_string_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_string__int (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    int param1 = json_array_get_int_element (param_array, 1);

    char* ret = ((char* (*)(int, GError **))func) (param1, &error);

    json_t *object = json_object ();
    searpc_set_string_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_string__string (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);

    char* ret = ((char* (*)(const char*, GError **))func) (param1, &error);

    json_t *object = json_object ();
    searpc_set_string_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_string__string_int (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);
    int param2 = json_array_get_int_element (param_array, 2);

    char* ret = ((char* (*)(const char*, int, GError **))func) (param1, param2, &error);

    json_t *object = json_object ();
    searpc_set_string_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_string__string_string (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);
    const char* param2 = json_array_get_string_or_null_element (param_array, 2);

    char* ret = ((char* (*)(const char*, const char*, GError **))func) (param1, param2, &error);

    json_t *object = json_object ();
    searpc_set_string_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_string__string_string_string (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);
    const char* param2 = json_array_get_string_or_null_element (param_array, 2);
    const char* param3 = json_array_get_string_or_null_element (param_array, 3);

    char* ret = ((char* (*)(const char*, const char*, const char*, GError **))func) (param1, param2, param3, &error);

    json_t *object = json_object ();
    searpc_set_string_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_string__string_string_string_string (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);
    const char* param2 = json_array_get_string_or_null_element (param_array, 2);
    const char* param3 = json_array_get_string_or_null_element (param_array, 3);
    const char* param4 = json_array_get_string_or_null_element (param_array, 4);

    char* ret = ((char* (*)(const char*, const char*, const char*, const char*, GError **))func) (param1, param2, param3, param4, &error);

    json_t *object = json_object ();
    searpc_set_string_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_string__string_string_string_string_int (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);
    const char* param2 = json_array_get_string_or_null_element (param_array, 2);
    const char* param3 = json_array_get_string_or_null_element (param_array, 3);
    const char* param4 = json_array_get_string_or_null_element (param_array, 4);
    int param5 = json_array_get_int_element (param_array, 5);

    char* ret = ((char* (*)(const char*, const char*, const char*, const char*, int, GError **))func) (param1, param2, param3, param4, param5, &error);

    json_t *object = json_object ();
    searpc_set_string_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_string__string_string_string_string_string (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);
    const char* param2 = json_array_get_string_or_null_element (param_array, 2);
    const char* param3 = json_array_get_string_or_null_element (param_array, 3);
    const char* param4 = json_array_get_string_or_null_element (param_array, 4);
    const char* param5 = json_array_get_string_or_null_element (param_array, 5);

    char* ret = ((char* (*)(const char*, const char*, const char*, const char*, const char*, GError **))func) (param1, param2, param3, param4, param5, &error);

    json_t *object = json_object ();
    searpc_set_string_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_string__string_string_string_string_string_string (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);
    const char* param2 = json_array_get_string_or_null_element (param_array, 2);
    const char* param3 = json_array_get_string_or_null_element (param_array, 3);
    const char* param4 = json_array_get_string_or_null_element (param_array, 4);
    const char* param5 = json_array_get_string_or_null_element (param_array, 5);
    const char* param6 = json_array_get_string_or_null_element (param_array, 6);

    char* ret = ((char* (*)(const char*, const char*, const char*, const char*, const char*, const char*, GError **))func) (param1, param2, param3, param4, param5, param6, &error);

    json_t *object = json_object ();
    searpc_set_string_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_string__string_string_string_string_string_int (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);
    const char* param2 = json_array_get_string_or_null_element (param_array, 2);
    const char* param3 = json_array_get_string_or_null_element (param_array, 3);
    const char* param4 = json_array_get_string_or_null_element (param_array, 4);
    const char* param5 = json_array_get_string_or_null_element (param_array, 5);
    int param6 = json_array_get_int_element (param_array, 6);

    char* ret = ((char* (*)(const char*, const char*, const char*, const char*, const char*, int, GError **))func) (param1, param2, param3, param4, param5, param6, &error);

    json_t *object = json_object ();
    searpc_set_string_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_string__string_string_string_string_string_string_string_string_string (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);
    const char* param2 = json_array_get_string_or_null_element (param_array, 2);
    const char* param3 = json_array_get_string_or_null_element (param_array, 3);
    const char* param4 = json_array_get_string_or_null_element (param_array, 4);
    const char* param5 = json_array_get_string_or_null_element (param_array, 5);
    const char* param6 = json_array_get_string_or_null_element (param_array, 6);
    const char* param7 = json_array_get_string_or_null_element (param_array, 7);
    const char* param8 = json_array_get_string_or_null_element (param_array, 8);
    const char* param9 = json_array_get_string_or_null_element (param_array, 9);

    char* ret = ((char* (*)(const char*, const char*, const char*, const char*, const char*, const char*, const char*, const char*, const char*, GError **))func) (param1, param2, param3, param4, param5, param6, param7, param8, param9, &error);

    json_t *object = json_object ();
    searpc_set_string_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_objlist__void (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;

    GList* ret = ((GList* (*)(GError **))func) (&error);

    json_t *object = json_object ();
    searpc_set_objlist_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_objlist__int (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    int param1 = json_array_get_int_element (param_array, 1);

    GList* ret = ((GList* (*)(int, GError **))func) (param1, &error);

    json_t *object = json_object ();
    searpc_set_objlist_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_objlist__int_int (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    int param1 = json_array_get_int_element (param_array, 1);
    int param2 = json_array_get_int_element (param_array, 2);

    GList* ret = ((GList* (*)(int, int, GError **))func) (param1, param2, &error);

    json_t *object = json_object ();
    searpc_set_objlist_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_objlist__int_int_int (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    int param1 = json_array_get_int_element (param_array, 1);
    int param2 = json_array_get_int_element (param_array, 2);
    int param3 = json_array_get_int_element (param_array, 3);

    GList* ret = ((GList* (*)(int, int, int, GError **))func) (param1, param2, param3, &error);

    json_t *object = json_object ();
    searpc_set_objlist_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_objlist__string (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);

    GList* ret = ((GList* (*)(const char*, GError **))func) (param1, &error);

    json_t *object = json_object ();
    searpc_set_objlist_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_objlist__string_int (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);
    int param2 = json_array_get_int_element (param_array, 2);

    GList* ret = ((GList* (*)(const char*, int, GError **))func) (param1, param2, &error);

    json_t *object = json_object ();
    searpc_set_objlist_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_objlist__string_int_int (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);
    int param2 = json_array_get_int_element (param_array, 2);
    int param3 = json_array_get_int_element (param_array, 3);

    GList* ret = ((GList* (*)(const char*, int, int, GError **))func) (param1, param2, param3, &error);

    json_t *object = json_object ();
    searpc_set_objlist_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_objlist__string_int_int_string (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);
    int param2 = json_array_get_int_element (param_array, 2);
    int param3 = json_array_get_int_element (param_array, 3);
    const char* param4 = json_array_get_string_or_null_element (param_array, 4);

    GList* ret = ((GList* (*)(const char*, int, int, const char*, GError **))func) (param1, param2, param3, param4, &error);

    json_t *object = json_object ();
    searpc_set_objlist_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_objlist__string_string (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);
    const char* param2 = json_array_get_string_or_null_element (param_array, 2);

    GList* ret = ((GList* (*)(const char*, const char*, GError **))func) (param1, param2, &error);

    json_t *object = json_object ();
    searpc_set_objlist_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_objlist__string_string_string (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);
    const char* param2 = json_array_get_string_or_null_element (param_array, 2);
    const char* param3 = json_array_get_string_or_null_element (param_array, 3);

    GList* ret = ((GList* (*)(const char*, const char*, const char*, GError **))func) (param1, param2, param3, &error);

    json_t *object = json_object ();
    searpc_set_objlist_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_objlist__string_string_int (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);
    const char* param2 = json_array_get_string_or_null_element (param_array, 2);
    int param3 = json_array_get_int_element (param_array, 3);

    GList* ret = ((GList* (*)(const char*, const char*, int, GError **))func) (param1, param2, param3, &error);

    json_t *object = json_object ();
    searpc_set_objlist_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_objlist__string_string_int_int (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);
    const char* param2 = json_array_get_string_or_null_element (param_array, 2);
    int param3 = json_array_get_int_element (param_array, 3);
    int param4 = json_array_get_int_element (param_array, 4);

    GList* ret = ((GList* (*)(const char*, const char*, int, int, GError **))func) (param1, param2, param3, param4, &error);

    json_t *object = json_object ();
    searpc_set_objlist_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_objlist__int_int_string (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    int param1 = json_array_get_int_element (param_array, 1);
    int param2 = json_array_get_int_element (param_array, 2);
    const char* param3 = json_array_get_string_or_null_element (param_array, 3);

    GList* ret = ((GList* (*)(int, int, const char*, GError **))func) (param1, param2, param3, &error);

    json_t *object = json_object ();
    searpc_set_objlist_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_object__void (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;

    GObject* ret = ((GObject* (*)(GError **))func) (&error);

    json_t *object = json_object ();
    searpc_set_object_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_object__int (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    int param1 = json_array_get_int_element (param_array, 1);

    GObject* ret = ((GObject* (*)(int, GError **))func) (param1, &error);

    json_t *object = json_object ();
    searpc_set_object_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_object__string (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);

    GObject* ret = ((GObject* (*)(const char*, GError **))func) (param1, &error);

    json_t *object = json_object ();
    searpc_set_object_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}


static char *
marshal_object__string_string (void *func, json_t *param_array, gsize *ret_len)
{
    GError *error = NULL;
    const char* param1 = json_array_get_string_or_null_element (param_array, 1);
    const char* param2 = json_array_get_string_or_null_element (param_array, 2);

    GObject* ret = ((GObject* (*)(const char*, const char*, GError **))func) (param1, param2, &error);

    json_t *object = json_object ();
    searpc_set_object_to_ret_object (object, ret);
    return searpc_marshal_set_ret_common (object, ret_len, error);
}

static void register_marshals()
{

    {
        searpc_server_register_marshal (searpc_signature_int__void(), marshal_int__void);
    }

    {
        searpc_server_register_marshal (searpc_signature_int__int(), marshal_int__int);
    }

    {
        searpc_server_register_marshal (searpc_signature_int__int_int(), marshal_int__int_int);
    }

    {
        searpc_server_register_marshal (searpc_signature_int__int_string(), marshal_int__int_string);
    }

    {
        searpc_server_register_marshal (searpc_signature_int__int_string_int(), marshal_int__int_string_int);
    }

    {
        searpc_server_register_marshal (searpc_signature_int__int_string_string(), marshal_int__int_string_string);
    }

    {
        searpc_server_register_marshal (searpc_signature_int__int_string_int_int(), marshal_int__int_string_int_int);
    }

    {
        searpc_server_register_marshal (searpc_signature_int__string(), marshal_int__string);
    }

    {
        searpc_server_register_marshal (searpc_signature_int__string_int(), marshal_int__string_int);
    }

    {
        searpc_server_register_marshal (searpc_signature_int__string_int_string(), marshal_int__string_int_string);
    }

    {
        searpc_server_register_marshal (searpc_signature_int__string_int_string_string(), marshal_int__string_int_string_string);
    }

    {
        searpc_server_register_marshal (searpc_signature_int__string_int_string_int_int(), marshal_int__string_int_string_int_int);
    }

    {
        searpc_server_register_marshal (searpc_signature_int__string_string(), marshal_int__string_string);
    }

    {
        searpc_server_register_marshal (searpc_signature_int__string_string_string(), marshal_int__string_string_string);
    }

    {
        searpc_server_register_marshal (searpc_signature_int__string_string_int(), marshal_int__string_string_int);
    }

    {
        searpc_server_register_marshal (searpc_signature_int__string_string_int_int(), marshal_int__string_string_int_int);
    }

    {
        searpc_server_register_marshal (searpc_signature_int__string_string_string_string(), marshal_int__string_string_string_string);
    }

    {
        searpc_server_register_marshal (searpc_signature_int__string_string_string_string_string(), marshal_int__string_string_string_string_string);
    }

    {
        searpc_server_register_marshal (searpc_signature_int__string_string_string_string_string_string(), marshal_int__string_string_string_string_string_string);
    }

    {
        searpc_server_register_marshal (searpc_signature_int__string_string_string_string_string_string_string(), marshal_int__string_string_string_string_string_string_string);
    }

    {
        searpc_server_register_marshal (searpc_signature_int__string_int64(), marshal_int__string_int64);
    }

    {
        searpc_server_register_marshal (searpc_signature_int__int_int64(), marshal_int__int_int64);
    }

    {
        searpc_server_register_marshal (searpc_signature_int__int_string_int64(), marshal_int__int_string_int64);
    }

    {
        searpc_server_register_marshal (searpc_signature_int64__void(), marshal_int64__void);
    }

    {
        searpc_server_register_marshal (searpc_signature_int64__string(), marshal_int64__string);
    }

    {
        searpc_server_register_marshal (searpc_signature_int64__int(), marshal_int64__int);
    }

    {
        searpc_server_register_marshal (searpc_signature_int64__int_string(), marshal_int64__int_string);
    }

    {
        searpc_server_register_marshal (searpc_signature_string__void(), marshal_string__void);
    }

    {
        searpc_server_register_marshal (searpc_signature_string__int(), marshal_string__int);
    }

    {
        searpc_server_register_marshal (searpc_signature_string__string(), marshal_string__string);
    }

    {
        searpc_server_register_marshal (searpc_signature_string__string_int(), marshal_string__string_int);
    }

    {
        searpc_server_register_marshal (searpc_signature_string__string_string(), marshal_string__string_string);
    }

    {
        searpc_server_register_marshal (searpc_signature_string__string_string_string(), marshal_string__string_string_string);
    }

    {
        searpc_server_register_marshal (searpc_signature_string__string_string_string_string(), marshal_string__string_string_string_string);
    }

    {
        searpc_server_register_marshal (searpc_signature_string__string_string_string_string_int(), marshal_string__string_string_string_string_int);
    }

    {
        searpc_server_register_marshal (searpc_signature_string__string_string_string_string_string(), marshal_string__string_string_string_string_string);
    }

    {
        searpc_server_register_marshal (searpc_signature_string__string_string_string_string_string_string(), marshal_string__string_string_string_string_string_string);
    }

    {
        searpc_server_register_marshal (searpc_signature_string__string_string_string_string_string_int(), marshal_string__string_string_string_string_string_int);
    }

    {
        searpc_server_register_marshal (searpc_signature_string__string_string_string_string_string_string_string_string_string(), marshal_string__string_string_string_string_string_string_string_string_string);
    }

    {
        searpc_server_register_marshal (searpc_signature_objlist__void(), marshal_objlist__void);
    }

    {
        searpc_server_register_marshal (searpc_signature_objlist__int(), marshal_objlist__int);
    }

    {
        searpc_server_register_marshal (searpc_signature_objlist__int_int(), marshal_objlist__int_int);
    }

    {
        searpc_server_register_marshal (searpc_signature_objlist__int_int_int(), marshal_objlist__int_int_int);
    }

    {
        searpc_server_register_marshal (searpc_signature_objlist__string(), marshal_objlist__string);
    }

    {
        searpc_server_register_marshal (searpc_signature_objlist__string_int(), marshal_objlist__string_int);
    }

    {
        searpc_server_register_marshal (searpc_signature_objlist__string_int_int(), marshal_objlist__string_int_int);
    }

    {
        searpc_server_register_marshal (searpc_signature_objlist__string_int_int_string(), marshal_objlist__string_int_int_string);
    }

    {
        searpc_server_register_marshal (searpc_signature_objlist__string_string(), marshal_objlist__string_string);
    }

    {
        searpc_server_register_marshal (searpc_signature_objlist__string_string_string(), marshal_objlist__string_string_string);
    }

    {
        searpc_server_register_marshal (searpc_signature_objlist__string_string_int(), marshal_objlist__string_string_int);
    }

    {
        searpc_server_register_marshal (searpc_signature_objlist__string_string_int_int(), marshal_objlist__string_string_int_int);
    }

    {
        searpc_server_register_marshal (searpc_signature_objlist__int_int_string(), marshal_objlist__int_int_string);
    }

    {
        searpc_server_register_marshal (searpc_signature_object__void(), marshal_object__void);
    }

    {
        searpc_server_register_marshal (searpc_signature_object__int(), marshal_object__int);
    }

    {
        searpc_server_register_marshal (searpc_signature_object__string(), marshal_object__string);
    }

    {
        searpc_server_register_marshal (searpc_signature_object__string_string(), marshal_object__string_string);
    }
}

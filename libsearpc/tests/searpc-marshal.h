
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

static void register_marshals()
{

    {
        searpc_server_register_marshal (searpc_signature_string__string_int(), marshal_string__string_int);
    }

    {
        searpc_server_register_marshal (searpc_signature_object__string(), marshal_object__string);
    }

    {
        searpc_server_register_marshal (searpc_signature_objlist__string_int(), marshal_objlist__string_int);
    }
}

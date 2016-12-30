
inline static gchar *
searpc_signature_int__string()
{
    return searpc_compute_signature ("int", 1, "string");
}


inline static gchar *
searpc_signature_objlist__int_int_string()
{
    return searpc_compute_signature ("objlist", 3, "int", "int", "string");
}


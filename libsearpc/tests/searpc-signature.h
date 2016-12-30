
inline static gchar *
searpc_signature_string__string_int()
{
    return searpc_compute_signature ("string", 2, "string", "int");
}


inline static gchar *
searpc_signature_object__string()
{
    return searpc_compute_signature ("object", 1, "string");
}


inline static gchar *
searpc_signature_objlist__string_int()
{
    return searpc_compute_signature ("objlist", 2, "string", "int");
}


FILE *sd_sys_fopen(const char *path, const char *mode)
{
    if (strcmp(path, "/sdcard/bad.jpg") == 0) {
        return NULL;  // simulate open failure
    }
    return fopen(path, mode);
}

size_t sd_sys_fread(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    static int calls;
    calls++;
    if (calls == 5) {
        return 0; // simulate read error mid-stream
    }
    return fread(ptr, size, nmemb, stream);
}

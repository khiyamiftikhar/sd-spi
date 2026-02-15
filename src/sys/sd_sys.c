#include "sd_sys.h"

__attribute__((weak))
FILE *sd_sys_fopen(const char *path, const char *mode)
{
    return fopen(path, mode);
}

__attribute__((weak))
size_t sd_sys_fread(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    return fread(ptr, size, nmemb, stream);
}

__attribute__((weak))
size_t sd_sys_fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    return fwrite(ptr, size, nmemb, stream);
}

__attribute__((weak))
int sd_sys_fseek(FILE *stream, long offset, int whence)
{
    return fseek(stream, offset, whence);
}

__attribute__((weak))
long sd_sys_ftell(FILE *stream)
{
    return ftell(stream);
}

__attribute__((weak))
int sd_sys_fflush(FILE *stream)
{
    return fflush(stream);
}

__attribute__((weak))
int sd_sys_fclose(FILE *stream)
{
    return fclose(stream);
}

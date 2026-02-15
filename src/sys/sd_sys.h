#pragma once

#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>

/* Weak wrappers around libc / FATFS */

FILE  *sd_sys_fopen(const char *path, const char *mode);
size_t sd_sys_fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
size_t sd_sys_fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
int    sd_sys_fseek(FILE *stream, long offset, int whence);
long   sd_sys_ftell(FILE *stream);
int    sd_sys_fflush(FILE *stream);
int    sd_sys_fclose(FILE *stream);

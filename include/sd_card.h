#pragma once

#include <stddef.h>
#include <stdbool.h>

typedef struct sd_file sd_file_t;

typedef enum {
    SD_MODE_READ,
    SD_MODE_WRITE,
    SD_MODE_APPEND
} sd_mode_t;

/* Open / Close */
sd_file_t *sd_open(const char *path, sd_mode_t mode);
void       sd_close(sd_file_t *f);

/* I/O */
size_t sd_read(sd_file_t *f, void *buf, size_t len);
size_t sd_write(sd_file_t *f, const void *buf, size_t len);

/* Control */
bool sd_seek(sd_file_t *f, long offset);
long sd_tell(sd_file_t *f);

/* Utility */
bool sd_flush(sd_file_t *f);

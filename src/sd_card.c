#include "sd_card.h"
#include "sys/sd_sys.h"
#include <stdlib.h>

struct sd_file {
    FILE *fp;
};

sd_file_t *sd_open(const char *path, sd_mode_t mode)
{
    const char *m = NULL;

    switch (mode) {
    case SD_MODE_READ:   m = "rb"; break;
    case SD_MODE_WRITE:  m = "wb"; break;
    case SD_MODE_APPEND: m = "ab"; break;
    default: return NULL;
    }

    FILE *fp = sd_sys_fopen(path, m);
    if (!fp) return NULL;

    sd_file_t *f = calloc(1, sizeof(sd_file_t));
    if (!f) {
        sd_sys_fclose(fp);
        return NULL;
    }

    f->fp = fp;
    return f;
}

void sd_close(sd_file_t *f)
{
    if (!f) return;
    if (f->fp) {
        sd_sys_fclose(f->fp);
    }
    free(f);
}

size_t sd_read(sd_file_t *f, void *buf, size_t len)
{
    if (!f || !f->fp) return 0;
    return sd_sys_fread(buf, 1, len, f->fp);
}

size_t sd_write(sd_file_t *f, const void *buf, size_t len)
{
    if (!f || !f->fp) return 0;
    return sd_sys_fwrite(buf, 1, len, f->fp);
}

bool sd_seek(sd_file_t *f, long offset)
{
    if (!f || !f->fp) return false;
    return (sd_sys_fseek(f->fp, offset, SEEK_SET) == 0);
}

long sd_tell(sd_file_t *f)
{
    if (!f || !f->fp) return -1;
    return sd_sys_ftell(f->fp);
}

bool sd_flush(sd_file_t *f)
{
    if (!f || !f->fp) return false;
    return (sd_sys_fflush(f->fp) == 0);
}

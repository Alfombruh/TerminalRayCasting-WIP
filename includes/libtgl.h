#ifndef LIBTGL_H
#define LIBTGL_H

#include <unistd.h>

typedef struct s_tgl{
    size_t lines;
    size_t columns;
    char emptyChar;
    char *image;
} t_tgl;

t_tgl *tgl_createCanvas(size_t lines, size_t columns);
size_t tgl_clearImage(t_tgl *tgl);
void tgl_printCanvas(t_tgl *tgl);
size_t tgl_pixelToCanvas(t_tgl *tgl ,char fillin, size_t x_position, size_t y_position);
void tgl_destroyCanvas(t_tgl *tgl);

#endif
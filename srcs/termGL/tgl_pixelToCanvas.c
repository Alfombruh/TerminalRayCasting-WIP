#include "libtgl.h"
#include <unistd.h>

size_t tgl_pixelToCanvas(t_tgl *tgl ,char fillin, size_t x_position, size_t y_position){
    if (y_position > tgl->lines || x_position > tgl->columns || ((y_position * tgl->columns) + (x_position)) > (tgl->columns * tgl->lines))
        return (1);
    tgl->image[(y_position * tgl->columns) + (x_position)] = fillin;
    return (0);
}
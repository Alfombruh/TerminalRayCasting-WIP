#include "termRC.h"
#include "libtgl.h"

size_t raycast(){
    t_tgl *tgl = tgl_createCanvas(LINES - 1, COLS, ' ');
    if (!tgl)
        return (errorMessage("error at Creating Canvas\n"));
    if (tgl_pixelToCanvas(tgl, 'x', 0, 1))
        return (errorMessage("Pixel put in wrong position\n"));
    tgl_printCanvas(tgl);
    tgl_destroyCanvas(tgl);
    return (0);
}
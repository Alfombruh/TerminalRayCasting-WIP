#include "termRC.h"
#include "libtgl.h"

size_t raycast(t_termRC *trc){
    t_tgl *tgl = tgl_createCanvas(LINES - 1, COLS, ' ');
    if (!tgl)
        return (errorMessage("error at Creating Canvas\n"));
    tgl_imageToCanvas(tgl, COLS / 2, LINES / 2, "./assets/images/face.xpm");
    if (tgl_pixelToCanvas(tgl, 'x', 0, 1))
        return (errorMessage("Pixel put in wrong position\n"));
    tgl_printCanvas(tgl);
    tgl_destroyCanvas(tgl);
    return (0);
}
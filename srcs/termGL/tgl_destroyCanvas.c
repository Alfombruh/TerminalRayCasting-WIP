#include "libtgl.h"
#include <stdlib.h>

void tgl_destroyCanvas(t_tgl *tgl){
    free(tgl->image);
    free(tgl);
}
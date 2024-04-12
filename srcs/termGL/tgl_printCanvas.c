#include "libtgl.h"

void tgl_printCanvas(t_tgl *tgl){
    int i = -1;
    while(tgl->image[++i])
            write(1, &tgl->image[i] ,1);
}
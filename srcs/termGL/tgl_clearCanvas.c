#include "libtgl.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

size_t tgl_clearImage(t_tgl *tgl)
{
    free(tgl->image);
        tgl->image = (char *)malloc(sizeof(char) * tgl->lines * tgl->columns + 1);
    if (!tgl->image)
        return (1);
    tgl->image[tgl->lines * tgl->columns] = '\0';
    memset(tgl->image, ' ', tgl->lines * tgl->columns);
    return (0);
}
#include "libtgl.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

t_tgl *tgl_createCanvas(size_t lines, size_t columns, char emptyCharacter){
    t_tgl *tgl = (t_tgl *)malloc(sizeof(t_tgl) * 1);
    if (!tgl)
        return (NULL);
    tgl->columns = columns;
    tgl->lines = lines;
    tgl->emptyChar = emptyCharacter;
    tgl->image = (char *)malloc(sizeof(char) * lines * columns + 1);
    if (!tgl->image)
        return (NULL);
    tgl->image[lines * columns] = '\0';
    memset(tgl->image, tgl->emptyChar, lines * columns);
    return (tgl);
}
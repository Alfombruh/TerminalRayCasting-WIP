#include "termRC.h"
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv){
    t_termRC *trc;
    trc = (t_termRC *)malloc(sizeof(t_termRC) * 1);
    if (trc == NULL)
        return (errorMessage("Mallo brokey\n"));
    if (argc != 2)
        return (errorMessage("Error (arguments)\n"));
    if (parseMap(argv[1], trc))
        return (errorMessage("Error (map)\n"));
    if (raycast(trc))
        return (errorMessage("Error (raycasting)\n"));
    system("leaks ./termRC maps/default.tgl");
    return  (0);
}
#include "termRC.h"
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv, char **env){
    if (argc != 2)
        return (errorMessage("Error (arguments)\n"));
    if (parseMap(argv[1]))
        return (errorMessage("Error (map)\n"));
    if (raycast())
        return (errorMessage("Error (raycasting)\n"));
    return  (0);
}
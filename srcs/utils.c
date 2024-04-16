#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void freeDouble(char **array){
    size_t i = -1;
    while(array[++i])
        free(array[i]);
    free(array);
}

size_t errorMessage(char *msg){
    write(2, msg, strlen(msg));
    return (1);
}
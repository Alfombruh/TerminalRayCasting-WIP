#include <stdlib.h>
#include <unistd.h>
#include <string.h>

size_t errorMessage(char *msg){
    write(2, msg, strlen(msg));
    return (1);
}
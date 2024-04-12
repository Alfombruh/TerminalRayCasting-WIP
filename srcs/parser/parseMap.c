#include "termRC.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

char *strjoin(char *str1, char *str2){
    char *str = (char *)malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 1));
    if (!str)
        return NULL;
    while(str1)
        *str++ = *str1++;
    while(str2)
        *str++ = *str2++;
    str[strlen(str1) + strlen(str2)] = '\0';
    return (str);
}

char *readFile(char *filename)
{
    int fd = open(filename, O_RDONLY, NULL);
    char **map;
    char *line;
    if (fd < 0)
        return (NULL);
    while(1){
        line = getNextLine(fd); //program this function
        //add line to MAp
    }
}

size_t parseMap(char *filename)
{
    if (!readFile(filename))
        return (1);
    return (0);   
}
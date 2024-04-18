#include "termRC.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

static size_t doubleArrayLen(char **array){
    size_t i = -1;
    while (array[++i])
            continue;
    return (i);
}

static char **joingString(char *line, char **map){
    size_t index = -1;
    size_t mapLen = doubleArrayLen(map);
    char **newMap = (char **)malloc(sizeof(char *) * (mapLen + 2));
    newMap[mapLen + 1] = NULL;
    while(++index <= mapLen + 2){
        if (index == mapLen){
            newMap[index] = line;
            newMap[index + 1] = NULL;
            break;
        }
        newMap[index] = map[index];
    }
    return newMap;
}

static size_t readFile(char *filename, t_termRC *trc)
{
    int fd = open(filename, O_RDONLY, NULL);
    if (fd < 0)
        return (1);
    char **map = (char **)malloc(sizeof(char *) * 1);
    *map = (char *)malloc(sizeof(char) * 1);
    *map = NULL;
    char *line;
    while(1){
        line = getNextLine(fd);
        if (line == NULL)
            break;
        map = joingString(line, map);
    }
    trc->map = map;
    return (0);
}

size_t parseMap(char *filename, t_termRC *trc)
{
    if (readFile(filename, trc))
        return (1);
    return (0);   
}
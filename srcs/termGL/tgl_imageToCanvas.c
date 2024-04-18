#include "libtgl.h"
#include <fcntl.h>

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

static int checkCh(char *str)
{
    int	i;

    i = 0;
    if (!str)
        return (0);
    while (str[i])
    {
        if (str[i] == '\n' || str[i] == '\0')
            return (1);
        i++;
    }
    return (0);
}

static char	*last(char *line, char c)
{
    char	*str;
    int		i;

    i = 0;
    while (line[i])
        i++;
    str = (char *) malloc(2 + i);
    if (!str)
        return (NULL);
    i = 0;
    while(line[i])
    {
        str[i] = line[i];
        i++;
    }
    str[i] = c;
    str[i + 1] = '\0';
    free(line);
    return (str);
}

static char *getNextLine(int fd)
{
    char	*line;
    char	buff;
    int		reader;

    line = malloc(1);
    if(fd < 0 || !line)
        return (NULL);
    line[0] = '\0';
    reader = 1;
    while (!checkCh(line) && reader != 0)
    {
        reader = read(fd, &buff, 1);
        if (reader <= 0)
        {
            if (reader == 0 || line[0] == '\0')
            {
                free(line);
                return (NULL);
            }
            return (line);
        }
        line = last(line, buff);
    }
    return (line);
}

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

static char *parseLine(char *line){
    char *str;

    while()
}

static char **readImage(int fd)
{
    if (fd < 0)
        return NULL;
    bool isImage = false;
    char **map = (char **)malloc(sizeof(char *) * 1);
    *map = (char *)malloc(sizeof(char) * 1);
    *map = NULL;
    char *line;
    while(1){
        line = getNextLine(fd);
        if (line == NULL)
            break;
        if (!strcmp("/* pixels */\n", line)) //checks if the following lines are gonna be the image
            isImage = true;
        if (isImage == true)
        {
            line = parseLine(line);
        }
        map = joingString(line, map);
    }
    return (map);
}

static void imageToCanvas(t_tgl *tgl, size_t x_position, size_t y_position, char **image)
{
    int i = -1, j = -1;
    while (image[++j])
        while(image[++i])
            tgl_pixelToCanvas(tgl, image[j][i], i + x_position,  j + y_position);
}


void tgl_imageToCanvas(t_tgl *tgl, size_t x_position, size_t y_position ,char *path)
{
    char **image;
    int fd = open(path, O_RDWR);
    if (fd <= 0)
        return ;
    image = readImage(fd);
    if (image == NULL)
        return ;
    imageToCanvas(tgl, x_position, y_position, image);
}
#ifndef TERMRC_H
#define TERMRC_H

# ifndef LINES
# define LINES 42
# endif
# ifndef COLS
# define COLS 42
# endif 

# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define YELLOW	"\033[0;33m"
# define BLUE 	"\033[0;34m"
# define PURPLE	"\033[0;35m"
# define CYAN	"\033[0;36m"
# define BOLD	"\033[0;1m"
# define CLOSE	"\033[0;0m"
# define BHRED	"\e[1;91m"
# define BHGRN	"\e[1;92m"
# define BHBLK "\e[1;90m"
# define BHYEL "\e[1;93m"
# define BHBLU "\e[1;94m"
# define BHMAG "\e[1;95m"
# define BHCYN "\e[1;96m"
# define BHWHT "\e[1;97m"

#include <stdlib.h>

typedef struct s_termRC{
    char **map;
} t_termRC;

//** utils.c **//
size_t errorMessage(char *msg);
void freeDouble(char **array);

//** raycast.c **//
size_t raycast(t_termRC *trc);

//** parser.c **//
size_t parseMap(char *filename, t_termRC *tr);
char *getNextLine(int fd);

#endif
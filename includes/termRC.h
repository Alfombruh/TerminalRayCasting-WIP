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

size_t errorMessage(char *msg);
size_t raycast();

size_t parseMap(char *filename);
char *getNextLine(int fd);

#endif
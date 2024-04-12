NAME = termRC 
CC = clang
CFLAGS = -o3
LINES = $(shell echo 'lines' | tput -S)
COLS = $(shell echo 'cols' | tput -S)
FILES = srcs/main \
		srcs/utils \
		srcs/raycast \
		srcs/parser/parseMap \
		srcs/parser/getNextLine 

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

all: $(NAME)

.c.o: $(SRCS)
	@$(CC) -I includes/ -DLINES=${LINES} -DCOLS=${COLS} $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
	$(MAKE) -C srcs/termGL
	$(CC) $(CFLAGS) srcs/termGL/TermGL.a $^ -o $@

sanitize:
	$(eval CFLAGS+=-fsanitize=address -g3)

sani: sanitize all

run: all
	@./$(NAME)

clean: 
	$(MAKE) clean -C srcs/termGL
	@rm -rf $(OBJS)

fclean: clean
	$(MAKE) fclean -C srcs/termGL
	@rm -rf $(NAME)

re: fclean all

.PHONY: all sanitize sani run clean fclean re
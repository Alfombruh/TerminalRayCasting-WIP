NAME = TermGL.a
CC = clang 
CFLAGS = -o3
FILES = tgl_clearCanvas \
		tgl_createCanvas \
		tgl_pixelToCanvas \
		tgl_printCanvas \
		tgl_destroyCanvas \

SRCS = $(addsuffix .c,$(FILES))
OBJS = $(addsuffix .o,$(FILES))

all: $(NAME)

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c $^ -o $@ 

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

sanitize:
	$(eval CFLAGS+=-fsanitize=address -g3)

sani: sanitize all

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re sani sanitize
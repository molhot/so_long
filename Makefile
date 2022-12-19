NAME = so_long
LIBMLX = minilibx-linux/libmlx_Linux.a

SRCS = test.c

OBJS = $(SRCS:.c=.o)

CC = gcc 

CFLAGS = -Wall -Wextra -Werror -I includes

all: $(NAME)

${NAME}: ${SRCS} ${LIBMLX}
	${CC} ${SRCS} ${LIBMLX} -lX11 -lXext -o ${NAME}

${LIBMLX}:
	make -C minilibx-linux/

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}
	make clean -C mlx/

re: fclean all

.PHONY:			all clean fclean re bonus
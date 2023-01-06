NAME = so_long
LIBMLX = minilibx-linux/libmlx_Linux.a

SRCS = gnl/get_next_line.c\
		basic_func/ft_bzero.c basic_func/ft_strchr.c basic_func/ft_strdup.c basic_func/ft_strjoin.c\
		basic_func/ft_strlcat.c basic_func/ft_strlcpy.c basic_func/ft_strlen.c basic_func/ft_strlen_withn.c\
		graphical_func/draw_map.c graphical_func/img_init.c graphical_func/read_mapinfo.c\
		movefunc/to_right.c movefunc/to_left.c movefunc/to_up.c movefunc/to_down.c\
		count_collectitem.c so_long_main.c\
		ft_printf/ft_printf.c ft_printf/ft_putnbr_string.c ft_printf/ft_putstr.c\
		map_checker/check_mandatory.c map_checker/check_map_main.c\
		map_checker/fill_check.c map_checker/map_rownum_check.c\
		relative_free.c

OBJS = $(SRCS:.c=.o)

CC = gcc -fsanitize=address -fno-omit-frame-pointer

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
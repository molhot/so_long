NAME = libftprintf.a

SRCS = ft_printf.c ft_putnbr_string.c ft_putstr.c

OBJS = $(SRCS:.c=.o)

CC = gcc 

CFLAGS = -Wall -Wextra -Werror -I includes

all: $(NAME)

$(NAME):$(OBJS)
	ar -rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f all

re: fclean all

.PHONY:			all clean fclean re bonus
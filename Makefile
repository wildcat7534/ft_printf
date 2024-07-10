NAME = libftprintf.a

HEADERS = headers/libft.h libftprintf.h

SOURCES = $(wildcard sources/ft_*.c)

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Werror -Wall -Wextra

CC = cc

AR = ar rcs

RM = rm -f

all: $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	$(AR) $@ $^

clean:
	$(RM) $(OBJECTS)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re

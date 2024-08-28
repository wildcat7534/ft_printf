NAME = libftprintf.a

HEADERS = /libft.h ft_printf.h

SOURCES = sources_ft_printf/ft_printf.c sources_ft_printf/ft_putcharlen.c sources_ft_printf/ft_putnbrhexlen.c \
		sources_ft_printf/ft_putnbrlen.c sources_ft_printf/ft_putptrlen.c sources_ft_printf/ft_putstrlen.c \
		sources_libft/ft_strlen.c

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Werror -Wall -Wextra

CC = cc

AR = ar rcs

RM = rm -f

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all: $(NAME)

%.o: %.c $(HEADERS)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	$(AR) $@ $^
	@echo "$(MAGENTA)ft_printf compiled!$(DEF_COLOR)"

clean:
	$(RM) $(OBJECTS)
	@echo "$(MAGENTA)Cleaned OBJECTS for ft_printf!$(DEF_COLOR)"
	
fclean: clean
	$(RM) $(NAME)
	@echo "$(MAGENTA)Cleaned NAME for ft_printf!$(DEF_COLOR)"


re: fclean all

.PHONY: clean fclean all re

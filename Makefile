NAME = simulator
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRCDIR  = ./src/
INCDIR  = ./inc/
OBJDIR  = ./obj/
FTDIR   = ./libft/
INCL	= $(wildcard $(INCDIR)*.h)

SRC =	main.c get_request.c ex_request.c order_get_functions.c order_add.c \
 		order_ex.c exit.c gnl_l.c tests.c

OBJ	=	$(addprefix $(OBJDIR),$(SRC:.c=.o))

LIBFT = $(FTDIR)libft.a

.PHONY: all clean fclean count

all: $(NAME)

obj:
	@echo "\033[32mПодготовка папок для объектных файлов:\033[90m"
	mkdir -p $(OBJDIR)
	@echo "\033[38;5;17m"

$(OBJDIR)%.o: $(SRCDIR)%.c $(INCL) | obj
	$(CC) $(CFLAGS) -I $(INCDIR) -I $(FTDIR)inc -o $@ -c $<

$(LIBFT): $(FT_SRCS)
	@echo "\033[0;32mСборка библиотеки LIBFT:\033[0;90m"
	make -C $(FTDIR)

$(NAME): $(LIBFT) $(OBJ)
	@echo "\033[0;94mСборка Simulator:\033[34m"
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\033[0;90m"

count:
	wc ./src/*.c ./inc/*.h

clean:
	rm -rf $(OBJDIR)
	make -sC $(FTDIR) clean

fclean: clean
	rm -f $(NAME)
	make -sC $(FTDIR) fclean

re: fclean all
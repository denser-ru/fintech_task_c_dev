NAME=libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCDIR	= ./src
INCDIR	= ./inc
OBJDIR  = ./obj
RAW_DIRS = $(shell find $(SRCDIR) -mindepth 1 -type d)
SRCDIRS = $(RAW_DIRS:./src/%=%)

FT_IS		= ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
				ft_iswhitespace.c
FT_MEM		= ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
				ft_memdel.c ft_memmove.c ft_memset.c
FT_LST		= ft_lstadd.c ft_lstdelcontent.c ft_lstmap.c ft_lstpushf.c \
				ft_lststrtoarr.c ft_lstcut.c ft_lstdelone.c ft_lstnew.c \
				ft_lstsize.c ft_lstdel.c ft_lstiter.c ft_lstpushb.c \
				ft_lststrsplit.c ft_lstputstr.c ft_lstputendl.c \
				ft_lstputstr_fd.c ft_lstputendl_fd.c
FT_PUT		= ft_putchar.c ft_putendl.c ft_putnbr.c ft_putnendl.c ft_putstr.c \
				ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putnstr.c \
				ft_putstr_fd.c ft_putnbr_to_mem.c ft_putmem.c \
				ft_putnendl_fd.c ft_putnstr_fd.c
FT_STR		= ft_strcat.c ft_strcmp.c ft_strdup.c ft_striteri.c ft_strlen.c \
				ft_strncat.c ft_strnequ.c ft_strrchr.c ft_strsub.c \
				ft_strchr.c ft_strcpy.c ft_strequ.c ft_strjoin.c ft_strmap.c \
				ft_strncmp.c ft_strnew.c ft_strsplit.c ft_strtrim.c \
				ft_strclr.c ft_strdel.c ft_striter.c ft_strlcat.c ft_strmapi.c \
				ft_strncpy.c ft_strnstr.c ft_strstr.c
FT_GET		= ft_getch.c ft_getint.c get_next_line.c
FT_OTHERS	= ft_atoi.c ft_atoi_n.c ft_bzero.c  ft_itoa.c ft_itoa_mem_d.c \
				ft_tolower.c ft_toupper.c
SRCS		= $(FT_IS) $(FT_MEM) $(FT_LST) $(FT_PUT) $(FT_STR) $(FT_GET) \
				$(FT_OTHERS) $(PRNTF) $(TERM) $(MAP)

SRC		= $(addprefix is/,$(FT_IS))
SRC		+= $(addprefix mem/,$(FT_MEM))
SRC		+= $(addprefix lst/,$(FT_LST))
SRC		+= $(addprefix put/,$(FT_PUT))
SRC		+= $(addprefix str/,$(FT_STR))
SRC		+= $(addprefix others/,$(FT_OTHERS))
SRC		+= $(addprefix get/,$(FT_GET))

OBJS	= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

INCS	= libft.h
INC		= $(addprefix $(INCDIR)/,$(INCS))

all: $(NAME)

obj:
	mkdir -p $(OBJDIR)
	mkdir -p $(addprefix $(OBJDIR)/,$(SRCDIRS))

$(OBJDIR)/is/%.o: $(SRCDIR)/is/%.c $(INC) | obj
	$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<

$(OBJDIR)/mem/%.o: $(SRCDIR)/mem/%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<

$(OBJDIR)/lst/%.o: $(SRCDIR)/lst/%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<

$(OBJDIR)/put/%.o: $(SRCDIR)/put/%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<

$(OBJDIR)/str/%.o: $(SRCDIR)/str/%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<

$(OBJDIR)/others/%.o: $(SRCDIR)/others/%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<

$(OBJDIR)/get/%.o: $(SRCDIR)/get/%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

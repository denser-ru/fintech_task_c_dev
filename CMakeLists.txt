cmake_minimum_required(VERSION 3.17)
project(minishell C)

set(CMAKE_C_STANDARD 99)

include_directories(inc libft/inc)

add_executable(simulator
        libft/inc/libft.h
        inc/simulator.h

        src/main.c

        libft/src/is
        libft/src/is/ft_isalnum.c
        libft/src/is/ft_isalpha.c
        libft/src/is/ft_isascii.c
        libft/src/is/ft_isdigit.c
        libft/src/is/ft_isprint.c
        libft/src/is/ft_iswhitespace.c
        libft/src/lst
        libft/src/lst/ft_lstadd.c
        libft/src/lst/ft_lstcut.c
        libft/src/lst/ft_lstdel.c
        libft/src/lst/ft_lstdelcontent.c
        libft/src/lst/ft_lstdelone.c
        libft/src/lst/ft_lstiter.c
        libft/src/lst/ft_lstmap.c
        libft/src/lst/ft_lstnew.c
        libft/src/lst/ft_lstpushb.c
        libft/src/lst/ft_lstpushf.c
        libft/src/lst/ft_lstsize.c
        libft/src/lst/ft_lststrsplit.c
        libft/src/lst/ft_lststrtoarr.c
        libft/src/lst/ft_lstputstr.c
        libft/src/lst/ft_lstputendl.c
        libft/src/lst/ft_lstputstr_fd.c
        libft/src/lst/ft_lstputendl_fd.c
        libft/src/mem
        libft/src/mem/ft_memalloc.c
        libft/src/mem/ft_memccpy.c
        libft/src/mem/ft_memchr.c
        libft/src/mem/ft_memcmp.c
        libft/src/mem/ft_memcpy.c
        libft/src/mem/ft_memdel.c
        libft/src/mem/ft_memmove.c
        libft/src/mem/ft_memset.c
        libft/src/others
        libft/src/others/ft_atoi.c
        libft/src/others/ft_atoi_n.c
        libft/src/others/ft_bzero.c
        libft/src/others/ft_itoa.c
        libft/src/others/ft_itoa_mem_d.c
        libft/src/others/ft_tolower.c
        libft/src/others/ft_toupper.c
        libft/src/put
        libft/src/put/ft_putchar.c
        libft/src/put/ft_putchar_fd.c
        libft/src/put/ft_putendl.c
        libft/src/put/ft_putendl_fd.c
        libft/src/put/ft_putmem.c
        libft/src/put/ft_putnbr.c
        libft/src/put/ft_putnbr_fd.c
        libft/src/put/ft_putnbr_to_mem.c
        libft/src/put/ft_putnendl.c
        libft/src/put/ft_putnstr.c
        libft/src/put/ft_putstr.c
        libft/src/put/ft_putstr_fd.c
        libft/src/put/ft_putnstr_fd.c
        libft/src/put/ft_putnendl_fd.c
        libft/src/str
        libft/src/str/ft_strcat.c
        libft/src/str/ft_strchr.c
        libft/src/str/ft_strclr.c
        libft/src/str/ft_strcmp.c
        libft/src/str/ft_strcpy.c
        libft/src/str/ft_strdel.c
        libft/src/str/ft_strdup.c
        libft/src/str/ft_strequ.c
        libft/src/str/ft_striter.c
        libft/src/str/ft_striteri.c
        libft/src/str/ft_strjoin.c
        libft/src/str/ft_strlcat.c
        libft/src/str/ft_strlen.c
        libft/src/str/ft_strmap.c
        libft/src/str/ft_strmapi.c
        libft/src/str/ft_strncat.c
        libft/src/str/ft_strncmp.c
        libft/src/str/ft_strncpy.c
        libft/src/str/ft_strnequ.c
        libft/src/str/ft_strnew.c
        libft/src/str/ft_strnstr.c
        libft/src/str/ft_strrchr.c
        libft/src/str/ft_strsplit.c
        libft/src/str/ft_strstr.c
        libft/src/str/ft_strsub.c
        libft/src/str/ft_strtrim.c
        libft/src/get/ft_getch.c
        libft/src/get/ft_getint.c
        libft/src/get/get_next_line.c
        src/exit.c src/get_request.c src/order_get_functions.c)
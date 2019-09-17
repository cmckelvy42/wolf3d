NAME = libft.a

CHK = srcs/chk/ft_digits.c \
	  srcs/chk/ft_digits_base.c \
	  srcs/chk/ft_isalnum.c \
	  srcs/chk/ft_isalpha.c \
	  srcs/chk/ft_isascii.c \
	  srcs/chk/ft_isdigit.c \
	  srcs/chk/ft_isprint.c \
	  srcs/chk/ft_isspace.c \
	  srcs/chk/ft_wordcount.c \
	  srcs/chk/ft_wordlen.c

CNV = srcs/cnv/ft_atoi.c \
	  srcs/cnv/ft_itoa.c \
	  srcs/cnv/ft_itoa_base.c \
	  srcs/cnv/ft_tolower.c \
	  srcs/cnv/ft_toupper.c \
	  srcs/cnv/ft_abs.c

MEM = srcs/mem/ft_bzero.c \
	  srcs/mem/ft_memalloc.c \
	  srcs/mem/ft_memccpy.c \
	  srcs/mem/ft_memchr.c \
	  srcs/mem/ft_memcmp.c \
	  srcs/mem/ft_memcpy.c \
	  srcs/mem/ft_memdel.c \
	  srcs/mem/ft_memmove.c \
	  srcs/mem/ft_memset.c

STR = srcs/str/ft_strcat.c \
	  srcs/str/ft_strclr.c \
	  srcs/str/ft_strcpy.c \
	  srcs/str/ft_strdup.c \
	  srcs/str/ft_striter.c \
	  srcs/str/ft_strjoin.c \
	  srcs/str/ft_strlen.c \
	  srcs/str/ft_strmapi.c \
	  srcs/str/ft_strncmp.c \
	  srcs/str/ft_strnequ.c \
	  srcs/str/ft_strnstr.c \
	  srcs/str/ft_strsplit.c \
	  srcs/str/ft_strsub.c \
	  srcs/str/ft_strchr.c \
	  srcs/str/ft_strcmp.c \
	  srcs/str/ft_strdel.c \
	  srcs/str/ft_strequ.c \
	  srcs/str/ft_striteri.c \
	  srcs/str/ft_strlcat.c \
	  srcs/str/ft_strmap.c \
	  srcs/str/ft_strncat.c \
	  srcs/str/ft_strncpy.c \
	  srcs/str/ft_strnew.c \
	  srcs/str/ft_strrchr.c \
	  srcs/str/ft_strstr.c \
	  srcs/str/ft_strccpy.c \
	  srcs/str/ft_strtrim.c \
	  srcs/str/ft_splitdel.c

PUT = srcs/put/ft_putchar.c \
	  srcs/put/ft_putchar_fd.c \
	  srcs/put/ft_putendl.c \
	  srcs/put/ft_putendl_fd.c \
	  srcs/put/ft_putnbr.c \
	  srcs/put/ft_putnbr_fd.c \
	  srcs/put/ft_putstr.c \
	  srcs/put/ft_putstr_fd.c

GET = srcs/get/get_next_line.c

LST = srcs/lst/ft_lstadd.c \
	  srcs/lst/ft_lstdel.c \
	  srcs/lst/ft_lstdelone.c \
	  srcs/lst/ft_lstiter.c \
	  srcs/lst/ft_lstmap.c \
	  srcs/lst/ft_lstnew.c \
	  srcs/lst/ft_lstsort.c \
	  srcs/lst/ft_lstrev.c \
	  srcs/lst/ft_lstcount.c

SRC = $(CHK) $(CNV) $(MEM) $(STR) $(PUT) $(GET) $(LST)
INC = includes/
OBJ = *.o

CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all
all: $(NAME)

$(NAME):
	@echo -e "\033[92mmaking libft...\033[0m"
	@$(CC) $(CFLAGS) -c $(SRC) -I $(INC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

.PHONY: clean
clean:
	@echo -e "\033[33mcleaning libft repository...\033[0m"
	@rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	@echo -e "\033[31mremoving libft library file...\033[0m"
	@rm -f $(NAME)

.PHONY: re
re: fclean all

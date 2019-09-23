# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/01 10:37:38 by rsmith            #+#    #+#              #
#    Updated: 2019/09/10 15:36:01 by cmckelvy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRCDIR = ./srcs/

SRC = main.c \
playa.c \
draw.c \
ray.c \
reader.c \
tiles.c \
normsucks.c \
hooks.c \
sound.c

 OBJECTS = $(SRC:.c=.o)

 INC = includes

 CC = gcc
 CFLAGS = -Wall -Wextra -Werror

 FRAMEWORK = -lSDL2 -lSDL2_image -lm -lpthread
 
 LIBFT = libft/libft.a

 .PHONY: all
 all: $(NAME)

 $(NAME):
	@make -C libft
	@echo "making"
	@$(CC) $(CFLAGS) -c $(addprefix $(SRCDIR), $(SRC)) -I $(INC) -g
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT) $(FRAMEWORK) fmod/libfmod.so -g -fsanitize=address 

.PHONY: clean
clean:
	@echo "cleaning"
	@/bin/rm -f $(OBJECTS)
	@make -C libft clean
.PHONY: fclean
fclean : clean
	rm -rf $(NAME)
	make -C libft fclean
.PHONY: re
re: fclean all

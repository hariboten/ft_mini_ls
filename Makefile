# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/02 12:35:08 by ewatanab          #+#    #+#              #
#    Updated: 2020/12/03 22:21:10 by ewatanab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_mini_ls
SRC		= main.c \
		  ft_mini_ls.c \
		  input.c \
		  sort.c \
		  output.c
OBJ		= $(SRC:%.c=%.o)
BSRC	= main_bonus.c \
		  ft_mini_ls.c \
		  input.c \
		  sort.c \
		  output.c \
		  fml_bonus.c
BOBJ	= $(BSRC:%.c=%.o)
LIBFT	= ./libft/libft.a
CFLAGS = -Wall -Werror -Wextra -g -O0
CC = gcc

all : $(NAME)

$(NAME) : $(OBJ)
	$(MAKE) -C ./libft
	$(CC) -o $(NAME) $(OBJ) $(LIBFT)

bonus : $(BOBJ)
	$(MAKE) -C ./libft
	$(CC) -o $(NAME) $(BOBJ) $(LIBFT)

clean :
	$(MAKE) -C ./libft clean
	rm -f $(OBJ) $(BOBJ)

fclean : clean
	$(MAKE) -C ./libft fclean
	rm -f $(NAME)

re : fclean all

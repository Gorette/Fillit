# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axbal <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 14:54:13 by axbal             #+#    #+#              #
#    Updated: 2017/12/04 22:36:07 by axbal            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = main.c		\
	   ft_read.c	\
	   ft_lst.c		\
	   ft_map.c		\

SRCO = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

LIB = ./Libft/libft.a

all: $(NAME)

$(NAME): libsvp $(SRCO)
	gcc -o $(NAME) $(SRCO) $(LIB)

$(SRCO): $(SRCS)
	gcc -c $(FLAGS) $(SRCS)

libsvp:
	make -C Libft

clean:
	rm -rf $(SRCO)
	make -C Libft clean

fclean: clean
	rm -rf $(NAME)
	make -C Libft fclean

re: fclean all

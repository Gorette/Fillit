# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axbal <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 14:54:13 by axbal             #+#    #+#              #
#    Updated: 2017/11/28 17:30:12 by axbal            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = main.c		\
	   ft_read.c	\
	   ft_lst.c		\

SRCO = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

LIB = ./Libft/libft.a

all: $(NAME)

$(NAME): $(SRCO)
	gcc -o $(NAME) $(SRCO) $(LIB)

$(SRCO): $(SRCS)
	gcc -c $(FLAGS) $(SRCS)

clean:
	rm -rf $(SRCO)

fclean: clean
	rm -rf $(NAME)

re: fclean all

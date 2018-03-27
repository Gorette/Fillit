# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axbal <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 14:54:13 by axbal             #+#    #+#              #
#    Updated: 2018/03/27 18:49:09 by axbal            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCDIR = src
SRCS = main.c				\
	   ft_read.c			\
	   ft_lst.c				\
	   ft_map.c				\
	   ft_fillit.c			\
	   ft_tetri_setup.c		\

OBJS = $(SRCS:.c=.o)

OBJDIR = obj
OBJS = $(SRCS:.c=.o)

SRC = $(addprefix $(SRCDIR)/,$(SRCS))
OBJ = $(addprefix $(OBJDIR)/,$(OBJS))

FLAGS = -Wall -Wextra -Werror

LIBFT = ./Libft/libft.a

INCLUDE = -Iincludes

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	cc -o $(NAME) $(OBJ) $(LIBFT)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir $(OBJDIR) 2> /dev/null || true
	cc $(FLAGS) $(INCLUDE) -o $@ -c $<

$(LIBFT):
	make -C libft

clean:
	make -C libft clean
	@rm -rf $(OBJDIR) 2> /dev/null || true

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean

re: fclean all

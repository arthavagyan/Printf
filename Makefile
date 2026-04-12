# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artavagy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/05 15:05:09 by artavagy          #+#    #+#              #
#    Updated: 2026/04/12 20:25:24 by artavagy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_itoa.c ft_printf.c ft_strdup.c ft_strjoin.c init.c parsers.c print_int.c utils.c print_unsigned.c

OBJS = $(SRC:.c=.o)

bonus: all

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -f  $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

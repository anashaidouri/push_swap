# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 16:58:26 by ahaidour          #+#    #+#              #
#    Updated: 2023/02/28 09:44:10 by ahaidour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_putnbr.c ft_putnbr_unsigned.c ft_strlen_p.c handle_conversion.c\
ft_printf.c ft_putchar.c ft_putnbr_hex.c ft_putstr.c

OBJ = ft_putnbr.o ft_putnbr_unsigned.o ft_strlen_p.o handle_conversion.o\
ft_printf.o ft_putchar.o ft_putnbr_hex.o ft_putstr.o

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

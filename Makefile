# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/30 23:41:00 by ahaidour          #+#    #+#              #
#    Updated: 2023/04/09 12:40:50 by ahaidour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC =  libft/ft_atoi.c libft/ft_split.c libft/ft_substr.c libft/ft_calloc.c libft/ft_bzero.c printf/handle_conversion.c\
		printf/ft_putchar.c printf/ft_putnbr.c printf/ft_putnbr_hex.c printf/ft_putnbr_unsigned.c printf/ft_putstr.c\
		printf/ft_printf.c printf/ft_strlen_p.c Check_arg.c push_swap.c libft/ft_strjoin.c libft/ft_strlen.c\
		libft/ft_strcmp.c erreur.c utils.c utils1.c small_sort.c rules.c rules1.c rules2.c sorts_utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

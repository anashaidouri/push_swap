# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/30 23:41:00 by ahaidour          #+#    #+#              #
#    Updated: 2023/05/03 17:16:01 by ahaidour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC =  ft_libft/ft_atoi.c ft_libft/ft_split.c ft_libft/ft_substr.c ft_libft/ft_calloc.c ft_libft/ft_putendl_fd.c ft_libft/ft_bzero.c ft_printf/handle_conversion.c\
		ft_printf/ft_putchar.c ft_printf/ft_putnbr.c ft_printf/ft_putnbr_hex.c ft_printf/ft_putnbr_unsigned.c ft_printf/ft_putstr.c\
		ft_printf/ft_printf.c ft_printf/ft_strlen_p.c Check_arg.c push_swap.c ft_libft/ft_strjoin.c ft_libft/ft_strlen.c\
		ft_libft/ft_strcmp.c erreur.c rules.c rules2.c small_sort.c sorts_utils.c sort_utils2.c\
		large_sort.c ft_libft/ft_lstnew_bonus.c \
		ft_libft/ft_lstadd_front_bonus.c ft_libft/ft_lstsize_bonus.c ft_libft/ft_lstlast_bonus.c \
		ft_libft/ft_lstadd_back_bonus.c ft_libft/ft_lstdelone_bonus.c ft_libft/ft_lstclear_bonus.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

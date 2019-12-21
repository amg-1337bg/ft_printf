# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 10:22:36 by bamghoug          #+#    #+#              #
#    Updated: 2019/12/19 20:21:25 by bamghoug         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_isalpha.c ft_itoa.c ft_memcmp.c ft_strdup.c \
ft_strjoin.c ft_strlen.c ft_strncmp.c ft_substr.c ft_inverse.c \
ft_printf.c ft_itoa_u.c ft_checkers.c ft_min_width.c ft_conversion_a.c \
ft_conversion_b.c ft_printf_utils.c ft_min_prec.c ft_perc_occur.c ft_memcpy.c \
ft_isdigit.c ft_putchar_fd.c ft_printf_utils2.c ft_checkers2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC)
	ar -rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ) $(OBJBONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

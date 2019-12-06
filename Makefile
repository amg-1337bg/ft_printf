# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 10:22:36 by bamghoug          #+#    #+#              #
#    Updated: 2019/11/22 11:27:16 by bamghoug         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c\
ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c\
ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c\
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c\
ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_inverse.c \
ft_printf.c ft_itoa_u.c

SRCBONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ = $(SRC:.c=.o)

OBJBONUS = $(SRCBONUS:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC)
	ar -rc $(NAME) $(OBJ)

bonus:
	gcc $(FLAGS) -c $(SRCBONUS)
	ar -rc $(NAME) $(OBJBONUS)

clean:
	rm -rf $(OBJ) $(OBJBONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

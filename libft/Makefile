# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/05 23:00:53 by pingpanu          #+#    #+#              #
#    Updated: 2022/07/11 14:06:48 by pingpanu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_putchar_fd.c \
      ft_putendl_fd.c \
      ft_isdigit.c \
      ft_bzero.c \
      ft_calloc.c \
      ft_strlen.c \
      ft_strcmp.c \
      ft_strlcpy.c \
      ft_atoi.c \
      ft_split.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@ ar rc $(NAME) $^

%.o : %.c
	@ gcc -c $(FLAGS) $^ -I ../include

clean :
	rm -f $(OBJ) 

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re

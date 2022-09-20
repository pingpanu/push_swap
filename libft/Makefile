# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/05 23:00:53 by pingpanu          #+#    #+#              #
#    Updated: 2022/09/20 23:53:52 by user             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_putchar_fd.c \
      ft_putendl_fd.c \
      ft_isdigit.c \
      ft_strlen.c \
      ft_bzero.c \
      ft_calloc.c \
      ft_strncmp.c \
      ft_strlcpy.c \
      ft_strjoin.c \
      ft_strchr.c \
      ft_atoi.c \
      ft_abs.c \
      ft_itoa.c \
      ft_split.c \
      ft_lstadd_front.c \
      ft_lstadd_back.c \
      ft_lstclear.c \
      ft_lstdelone.c \
      ft_lstlast.c \
      ft_lstnew.c \
      ft_lstsize.c \
      get_next_line.c

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

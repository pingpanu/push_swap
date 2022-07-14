# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 14:49:15 by pingpanu          #+#    #+#              #
#    Updated: 2022/07/14 10:31:05 by user             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#variables
NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror
SDIR = srcs
LIB = libft
INC = include

#color
DEFCO = '\033[0m'
RED = '\033[0;31m'
GREEN = '\033[0;32m'
YELLOW = '\033[0;33m'
BLUE = '\033[0;34m'
MAGENTA = '\033[0;35m'
CYAN = '\033[0;36m'

#sources
SRC = 	srcs/main.c \
	srcs/check_argvs.c \

OBJ = $(SRC.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	 @ echo "$(YELLOW)Make libft.a library$(DEFCO)"
	 @ make -C $(LIB)
	 @ echo "$(GREEN)libft.a created$(DEFCO)"
	 @ $(CC) $(FLAGS) $(OBJ) -L $(LIB) -lft -I $(INC) -o $(NAME)
	 @ echo "$(GREEN)$(NAME) created$(DEFCO)" 

%.o : %.c
	 @ $(CC) -c $(FLAGS) $(SRC) -I $(INC) 

clean:
	 @ make clean -C $(LIB)
	 @ echo "$(YELLOW)libft.a removed$(DEFCO)"
	 @ rm $(OBJ) 
	 @ echo "$(GREEN)Object files removed$(DEFCO)"

fclean: clean
	 @ rm -f $(NAME)
	 @ make fclean -C $(LIB)
	 @ echo "$(GREEN)$(NAME) removed$(DEFCO)"

re: fclean all

norm:
	 @ norminette $(SRCS) $(INC) $(LIB) | grep -v Norme -B1 || true

.PHONY: all clean fclean res

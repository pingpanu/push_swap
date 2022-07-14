# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 14:49:15 by pingpanu          #+#    #+#              #
#    Updated: 2022/07/14 14:12:31 by pingpanu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#variables
NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror
SDIR = srcs/
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
SRC_NAME = 	main.c \
		check_argvs.c \

SRCS = $(addprefix $(SDIR), $(SRC_NAME))
OBJS = $(addprefix $(SDIR), $(SRC_NAME:.c=.o))

all : $(NAME)

$(NAME) : $(OBJS)
	 @ echo "$(YELLOW)Make libft.a library$(DEFCO)"
	 @ make -C $(LIB)
	 @ echo "$(GREEN)libft.a created$(DEFCO)"
	 @ $(CC) $(FLAGS) $(OBJS) -L $(LIB) -lft -I $(INC) -o $(NAME)
	 @ echo "$(GREEN)$(NAME) created$(DEFCO)" 

$(SDIR)%.o : $(SDIR)%.c
	 @ $(CC) $(FLAGS) -c $< -o $@ -I $(INC) 

clean:
	 @ make clean -C $(LIB)
	 @ echo "$(YELLOW)libft.a removed$(DEFCO)"
	 @ rm $(OBJS) 
	 @ echo "$(GREEN)Object files removed$(DEFCO)"

fclean: clean
	 @ rm -f $(NAME)
	 @ make fclean -C $(LIB)
	 @ echo "$(GREEN)$(NAME) removed$(DEFCO)"

re: fclean all

norm:
	 @ norminette $(SRCS) $(INC) $(LIB) | grep -v Norme -B1 || true

.PHONY: all clean fclean res
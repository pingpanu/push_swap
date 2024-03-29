# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 14:49:15 by pingpanu          #+#    #+#              #
#    Updated: 2022/09/21 00:12:44 by user             ###   ########.fr        #
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
SRC_NAME = 	push_swap.c \
			parse_argv.c \
			utils_check.c \
			get_param.c \
			sorting_ops.c \
			insertion_sort.c \
			insert_utils.c \
			quick_sort.c \
			utils_algo.c \
			push.c \
			swap.c \
			rotate.c \
			r_rotate.c \
#bonus
BOS_NAME =	checker_main.c \
			parse_argv.c \
			utils_check.c \
			checker_sort.c \
			check_push.c \
			check_swap.c \
			check_rotate.c \
			check_rrotate.c \

OBJS = $(addprefix $(SDIR), $(SRC_NAME:.c=.o))
OBJ_BO = $(addprefix $(SDIR), $(BOS_NAME:.c=.o))

all : $(NAME)

$(NAME) : $(OBJS)
	@ echo "$(YELLOW)Make libft.a library$(DEFCO)"
	@ make -C $(LIB)
	@ echo "$(GREEN)libft.a created$(DEFCO)"
	@ $(CC) $(FLAGS) $^ -L $(LIB) -lft -I $(INC) -o $(NAME)
	@ echo "$(GREEN)$(NAME) created$(DEFCO)" 

$(SDIR)%.o : $(SDIR)%.c
	@ $(CC) $(FLAGS) -c $< -o $@ -I $(INC) 

bonus: $(OBJ_BO)
	@ make -C $(LIB) --silent
	@ $(CC) $(FLAGS) $^ -L $(LIB) -lft -I $(INC) -o checker 
	@ echo "$(GREEN)My checker created$(DEFCO)"

clean:
	@ make clean -C $(LIB)
	@ echo "$(YELLOW)libft.a removed$(DEFCO)"
	@ rm $(SDIR)*.o 
	@ echo "$(GREEN)Object files removed$(DEFCO)"

fclean: clean
	@ rm -f $(NAME)
	@ make fclean -C $(LIB)
	@ echo "$(GREEN)$(NAME) removed$(DEFCO)"

re: fclean all

norm:
	@ norminette $(SRCS) $(INC) $(LIB) | grep -v Norme -B1 || true

.PHONY: all clean fclean res

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zpalfi <zpalfi@student.42barcelon>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 12:16:53 by zpalfi            #+#    #+#              #
#    Updated: 2022/04/05 17:16:18 by zpalfi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

#--------------- DIRS ---------------#

INCLUDE_DIR	= include
SRC_DIR		= src
OBJS_DIR	= objs

#--------------- FILES ---------------#

INC				= -I $(INCLUDE_DIR)

SRC				= free.c \
				  time.c \
				  init.c \
				  print.c \
				  check.c \
				  error.c \
				  philo.c \
				  utils.c \
				  routine.c \

OBJ				= $(addprefix $(OBJS_DIR)/,$(SRC:.c=.o))

#--------------- COMPILATION ---------------#

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g $(INC)

#--------------- RULES ---------------#

objs/%.o:src/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $(CFLAGS) -o $@ $^
	@echo "Compiling $^"

all:	$(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)
	@echo "Built $(NAME)"

clean:
	@rm -rf $(OBJS_DIR)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all re clean fclean

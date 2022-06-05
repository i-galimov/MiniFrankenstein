# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phella <phella@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 18:31:58 by rtire             #+#    #+#              #
#    Updated: 2022/06/05 15:08:48 by phella           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SOURCE = main.c free.c shlvl.c utils.c init.c signals.c preparsing.c split_mod.c\
		quotes.c dollar.c preparsing_utils.c redirects.c heredoc.c new_list_ops.c\
		parsing.c 

HEADER = minishell.h

OBJ = $(SOURCE:%.c=%.o)

CFLAGS		= -Wall -Werror -Wextra #-g

READLINE	= -lreadline

CC = gcc

LIBFT = libft/libft.a

BLUE='\033[0;34m'
GRAY='\033[2;37m'
GREEN='\033[0;32m'
RED='\033[0;31m'

.PHONY : all clean fclean re

all: $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	@echo $(GREEN)"➤	 - Compiling $(NAME)..."
	@make -C ./libft/
	@$(CC) $(CFLAGS) -I$(HEADER) $(LIBFT) $(READLINE) $(OBJ) -o $(NAME)
	@echo $(GREEN)"- COMPILED -"

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@
	@printf $(BLUE)"█"

clean :
	@echo $(GREEN) "     - Removing object files..."
	@rm -rf $(OBJ)
	@make clean -C ./libft

fclean : clean
	@echo $(GREEN)"      - Removing $(NAME)..."
	@$(RM) $(NAME)
	@echo $(RED)"- REMOVED $(NAME) -"
	@make fclean -C ./libft

re     :	fclean all

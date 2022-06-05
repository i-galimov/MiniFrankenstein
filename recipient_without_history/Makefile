# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phella <phella@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 18:31:58 by rtire             #+#    #+#              #
#    Updated: 2022/06/05 16:41:03 by phella           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SOURCE = main.c free.c shlvl.c utils.c init.c signals.c preparsing.c split_mod.c\
		quotes.c dollar.c preparsing_utils.c redirects.c heredoc.c parsing.c \
		1new_list_ops.c 1multyexe.c 1exe_utils.c \
		1exit.c 1pwd.c 1unset.c 1echo.c 1export.c 1cd.c 1env.c 1export_utils.c 1export_utils2.c\
		1cd_utils.c 1ft_join.c

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

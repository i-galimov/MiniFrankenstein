# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phella <phella@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 18:31:58 by rtire             #+#    #+#              #
#    Updated: 2022/06/06 23:04:11 by phella           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

MAIN = main.c

SOURCE = free.c utils.c init.c signals.c preparsing.c split_mod.c\
		quotes.c dollar.c preparsing_utils.c redirects.c heredoc.c parsing.c lists.c\
		ft_cd.c ft_echo.c ft_env.c ft_exit.c ft_export.c ft_pwd.c ft_unset.c\
        pipex_for_minishell.c save_env.c check_buildin.c var_env_parser.c\
        t_envar_list_ops.c temp_env.c minizhopa.c free_env.c

HEADER = minishell.h

OBJ = $(SOURCE:%.c=%.o)

CFLAGS		= -Wall -Werror -Wextra -g

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
	@$(CC) $(CFLAGS) -I$(HEADER) $(LIBFT) $(READLINE) $(MAIN) $(OBJ) -o $(NAME)
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

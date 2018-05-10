# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkhalfao <kkhalfao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/15 12:47:48 by kkhalfao          #+#    #+#              #
#    Updated: 2017/10/10 16:33:53 by kkhalfao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

CCRED =	"\033[0;31m"
CCYELLOW = "\033[0;33m"
CCGREEN = "\033[0;32m"
CCEND = "\033[0m"

SRC_PATH = src
SRC_NAME = check_error.c filler.c init_struct.c parsing.c resolve_map.c territory.c count_territory.c
OBJ_PATH = objs
CPPFLAGS = -Iincludes

LIBPATH = libft
LDFLAGS = -Llibft
LDLIBS = -lft

NAME = kkhalfao.filler

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@make all -C $(LIBPATH)
	@$(CC) -o $@ $(LDFLAGS) $(LDLIBS) $(OBJ)
	@echo $(CCGREEN) filler OK $(CCEND)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@make clean -C $(LIBPATH)
	@echo $(CCRED)
	@rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo $(CCEND)

fclean: clean
	@make fclean -C $(LIBPATH)
	@echo $(CCRED)
	@rm -fv $(NAME)
	@echo $(CCEND)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

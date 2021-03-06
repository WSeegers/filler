# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/01 09:35:18 by wseegers          #+#    #+#              #
#    Updated: 2018/06/03 20:31:22 by wseegers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wseegers.filler
CC = clang
CFLAGS = -Werror -Wall -Wextra 
INC = -I toolkit-wtc/include -I src
LIB = toolkit-wtc/toolkit-wtc.a

SRC_PATH = src
MAIN = $(addprefix $(SRC_PATH)/, filler.c)
SRC = get_gameinfo.c parse_map.c init_game.c parse_token.c eval_map.c\
	  eval_token.c place_token.c
BIN_PATH = bin
BIN := $(SRC:%.c=$(BIN_PATH)/%.o)
DEP := $(BIN:%.o=%.d)

all : make_lib $(NAME)

make_lib :
	make -C toolkit-wtc

$(NAME) : $(MAIN) $(BIN)
	$(CC) $(CFLAGS) $(INC) -o $@ $^ $(LIB)

$(BIN_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(BIN_PATH)
	$(CC) $(CFLAGS) $(INC) -MMD -c $< -o $@

-include $(DEP)

clean :
	rm -rf $(BIN_PATH)

fclean : clean
	rm -f $(NAME)
	make -C toolkit-wtc

re : fclean all

.PHONEY : all  make_all  clean  fclean  re

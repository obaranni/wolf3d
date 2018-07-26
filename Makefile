#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obaranni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/25 15:42:09 by obaranni          #+#    #+#              #
#    Updated: 2017/10/25 20:47:46 by obaranni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 				wolf3d

LIBFT =				libft.a

SRC_DIR =			./src/
OBJ_DIR =			./obj/
HEAD_DIR =			./Headers/
LIBFT_DIR =			 ./libft/

SRC_FILES =			$(shell ls $(SRC_DIR))
OBJ_FILES =			$(SRC_FILES:.c=.o)

SRC =				$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ =				$(addprefix $(OBJ_DIR), $(OBJ_FILES))


HEADER =			wolf.h
LIBFT_INC =			$(LIBFT_DIR)
INC =				-I $(LIBFT_DIR)
MLX_FLAGS =			-lmlx -framework Opengl -framework Appkit

LIBFT_FLAGS =		-L $(LIBFT_DIR) -lft
CC_FLAGS =			-Werror -Wextra -Wall
FLAGS :=			$(CC_FLAGS) $(LIBFT_FLAGS) $(MLX_FLAGS)

CC =				gcc

all: $(NAME)

$(shell mkdir obj)
$(NAME): $(LIBFT_DIR)$(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(DEBUG) $(FLAGS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(FT_LS_INC)$(FT_LS_HEADER)
	$(CC) $(CC_FLAGS) $(INC) -c $< -o $@  

$(LIBFT_DIR)$(LIBFT):
	make -s -C $(LIBFT_DIR)

$(MLX_DIR)$(MLX):
	make -s -C $(MLX_DIR)
	
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

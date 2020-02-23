# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bshaland <bshaland@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/18 19:45:27 by aenstein          #+#    #+#              #
#    Updated: 2020/02/23 20:48:58 by bshaland         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c\
	draw_map.c\
	key_utils.c\
	read_file.c\
	utils.c\
	utils2.c\
	utils3.c\
	color.c\
	projection.c

OBJ = $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC = gcc
FLAGS = -Wall -Wextra -Werror -O3

MLX = ./minilibx_macos/
MLX_LIB = $(addprefix $(MLX), libmlx.a)
MLX_INC = -I ./minilibx_macos
MLX_LNK = -L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit

FT = ./libft/
FT_LIB = $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -lft

SRCDIR	= ./sourses/
INCDIR	= ./includes/
OBJDIR	= ./objects/

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(FLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	make -C $(FT)

$(MLX_LIB):
	make -C $(MLX)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(MLX_LNK) -o $(NAME) $(FT_LNK) 

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean
	make -C $(MLX) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all
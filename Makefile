# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tosinga <tosinga@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 15:03:10 by tosinga           #+#    #+#              #
#    Updated: 2022/03/09 13:22:33 by tosinga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	so_long

SRCS 	= 	src/so_long.c 				\
			src/validate_map.c			\
			src/utils.c					\
			src/utils_fileread.c		\
			src/utils_imgs.c			\
			src/get_next_line.c			\
			src/get_next_line_utils.c	\
			src/make_game.c				\
			src/game_play.c				\
			src/player_moves.c

LIB				= ./libft/libft.a
LIBFT_LOC		= libft
LIBFT_LIB		= libft/libft.a
PRINTF_LOC		= libftprintf
PRINTF_LIB		= libftprintf/libftprintf.a
PRINTF_FLAGS	= -Llibftprintf -lftprintf 
MLX_LOC			= mlx
MLX_LIB			= mlx/libmlx.a
MLX_FLAGS		= -Lmlx -lmlx -framework OpenGL -framework AppKit	
CFLAGS 			= -Wall -Wextra
CC				= gcc
HEADER 			= src/so_long.h

OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER)
	@$(MAKE) -s -C $(LIBFT_LOC)
	@$(MAKE) -s -C $(MLX_LOC)
	@$(MAKE) -s -C $(PRINTF_LOC)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(PRINTF_FLAGS) $(OBJECTS) $(PRINTF_LIB) $(MLX_LIB) $(LIB) -o $(NAME)
	@echo "maked"

%.o : %.c
	@$(CC) $(CFLAGS) -Imlx -c -o $@ $<

clean:
	@$(RM) $(OBJECTS)
	@$(MAKE) -s -C $(dir $(LIB)) clean
	@$(MAKE) -s -C $(MLX_LOC) clean
	@$(MAKE) -s -C $(PRINTF_LOC) clean
	@echo "maked clean"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -s -C $(dir $(LIB)) fclean
	@echo "maked fclean"

re: fclean all

.PHONY: all clean fclean re
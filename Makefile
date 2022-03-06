NAME 	= 	so_long

SRCS 	= 	so_long.c 				\
			utils.c					\
			utils_fileread.c		\
			utils_imgs.c			\
			get_next_line.c			\
			get_next_line_utils.c	\
			make_game.c				\
			game_play.c

LIB				= ./libft/libft.a
LIBFT_LOC		= libft
LIBFT_LIB		= libft/libft.a
PRINTF_LOC		= libftprintf
PRINTF_LIB		= libftprintf/libftprintf.a
PRINTF_FLAGS	= -Llibftprintf -lftprintf 
MLX_LOC			= mlx
MLX_LIB			= mlx/libmlx.a
MLX_FLAGS		= -Lmlx -lmlx -framework OpenGL -framework AppKit	
CFLAGS 			= -Wall -Wextra -Werror -fsanitize=address -g1
CC				= gcc
HEADER 			= so_long.h

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
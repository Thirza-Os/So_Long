/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tosinga <tosinga@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 15:03:19 by tosinga       #+#    #+#                 */
/*   Updated: 2022/03/08 15:03:20 by tosinga       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include "./mlx/mlx.h"
# include "./libftprintf/libftprintf.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# define ESC 53
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2

typedef struct s_vector
{
	int	height;
	int	width;
}	t_vector;

typedef struct s_image
{
	void		*img_pointer;
	t_vector	*size;
}	t_img;

typedef struct s_program
{
	void		*mlx;
	void		*window;
	char		**grid;
	int			max_collectables;
	int			counter_collectables;
	int			key_presses;
	t_vector	player_position;
	t_vector	*program_size;
	t_vector	*max_xy;
	t_img		*player;
	t_img		*player_copy;
	t_img		*player_two;
	t_img		*collectable;
	t_img		*exit;
	t_img		*wall;
	t_img		*ground;
	t_img		*dave;
}	t_program;

char			*get_next_line(int fd);
unsigned long	ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);

void			validate_map(t_program *param);
void			print_error(char *message);
int				check_ber(char *argv);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			new_window(t_program *program, int width, \
				int height, char *name);
char			*ft_strjoin_free_so_long(char const *s1, char const *s2);
void			*ft_malloc_check(void *s);
void			load_imgs(t_program *program);
void			parse_map(char *argv, t_program *program);
void			get_xy(t_program *program);
void			make_game(t_program *program);
int				check_ber(char *argv);
void			put_player(t_program *program);
void			init_playground(t_program *program, int y_count, int x_count);
void			right_move(t_program *program);
void			left_move(t_program *program);
void			down_move(t_program *program);
void			up_move(t_program *program);
int				check_position(int y, int x, t_program *program);
int				display_score(t_program *program);

#endif

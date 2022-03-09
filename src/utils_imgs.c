/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_imgs.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tosinga <tosinga@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 15:03:26 by tosinga       #+#    #+#                 */
/*   Updated: 2022/03/08 15:03:27 by tosinga       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_img(t_program *program, t_img **img, char *path)
{
	(*img) = ft_malloc_check((t_img *)malloc(sizeof(t_img)));
	(*img)->size = ft_malloc_check((t_vector *)malloc(sizeof(t_vector)));
	(*img)->img_pointer = mlx_xpm_file_to_image(program->mlx, \
		path, &(*img)->size->width, &(*img)->size->height);
}

void	load_imgs(t_program *program)
{
	init_img(program, &program->player, "./imgs/block_player_one.xpm");
	init_img(program, &program->player_copy, "./imgs/block_player_one.xpm");
	init_img(program, &program->player_two, "./imgs/block_player_two.xpm");
	init_img(program, &program->exit, "./imgs/block_end.xpm");
	init_img(program, &program->wall, "./imgs/wall.xpm");
	init_img(program, &program->ground, "./imgs/empty_space.xpm");
	init_img(program, &program->dave, "./imgs/block_enemy.xpm");
	init_img(program, &program->collectable, "./imgs/fish.xpm");
}

int	display_score(t_program *program)
{
	char	*score;

	score = ft_itoa(program->key_presses);
	mlx_string_put(program->mlx, program->window, 1, 10, 10, "Keys: ");
	mlx_string_put(program->mlx, program->window, 1, 20, 10, score);
	free(score);
	return (0);
}

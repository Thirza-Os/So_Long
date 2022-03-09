/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tosinga <tosinga@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 15:03:07 by tosinga       #+#    #+#                 */
/*   Updated: 2022/03/08 15:03:08 by tosinga       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_player(t_program *program, int y_count, int x_count)
{
	mlx_put_image_to_window(program->mlx, program->window, \
		program->ground->img_pointer, x_count * 80, y_count * 80);
	program->player_position.height = y_count;
	program->player_position.width = x_count;
	program->grid[y_count][x_count] = '0';
}

void	init_playground(t_program *program, int y_count, int x_count)
{
	if (program->grid[y_count][x_count] == 'P')
		display_player(program, y_count, x_count);
	if (program->grid[y_count][x_count] == '1')
		mlx_put_image_to_window(program->mlx, program->window, \
			program->wall->img_pointer, x_count * 80, y_count * 80);
	if (program->grid[y_count][x_count] == '0')
		mlx_put_image_to_window(program->mlx, program->window, \
			program->ground->img_pointer, x_count * 80, y_count * 80);
	if (program->grid[y_count][x_count] == 'E')
		mlx_put_image_to_window(program->mlx, program->window, \
			program->exit->img_pointer, x_count * 80, y_count * 80);
	if (program->grid[y_count][x_count] == 'D')
		mlx_put_image_to_window(program->mlx, program->window, \
			program->dave->img_pointer, x_count * 80, y_count * 80);
	if (program->grid[y_count][x_count] == 'C')
	{
		mlx_put_image_to_window(program->mlx, program->window, \
			program->collectable->img_pointer, x_count * 80, y_count * 80);
	}
}

void	make_game(t_program *program)
{
	int	y_count;
	int	x_count;

	y_count = 0;
	while (y_count < program->max_xy->height)
	{
		x_count = 0;
		while (x_count < program->max_xy->width)
		{
			init_playground(program, y_count, x_count);
			x_count++;
		}
		y_count++;
	}
}

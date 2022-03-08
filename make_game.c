#include "so_long.h"

void	intit_playground(t_program *program, int y_count, int x_count)
{
	if (program->grid[y_count][x_count] == 'P')
	{
		mlx_put_image_to_window(program->mlx, program->window, \
			program->ground->img_pointer, x_count * 80, y_count * 80);
			program->player_position->height = y_count;
			program->player_position->width = x_count;
			program->grid[y_count][x_count] = '0';
	}
	if (program->grid[y_count][x_count] == '1')
		mlx_put_image_to_window(program->mlx, program->window, \
			program->wall->img_pointer, x_count * 80, y_count * 80);
	if (program->grid[y_count][x_count] == '0')
		mlx_put_image_to_window(program->mlx, program->window, \
			program->ground->img_pointer, x_count * 80, y_count * 80);
	if (program->grid[y_count][x_count] == 'E')
		mlx_put_image_to_window(program->mlx, program->window, \
			program->exit->img_pointer, x_count * 80, y_count * 80);
	if (program->grid[y_count][x_count] == 'C')
	{
		mlx_put_image_to_window(program->mlx, program->window, \
			program->collectable->img_pointer, x_count * 80, y_count * 80);
	}
}

void	make_game(t_program *program)
{
	int		y_count;
	int		x_count;

	y_count = 0;
	x_count = 0;
	while (y_count < program->max_xy->height)
	{
	x_count = 0;
		while (x_count < program->max_xy->width)
		{
			intit_playground(program, y_count, x_count);
			x_count++;
		}
	y_count++;
	}
}

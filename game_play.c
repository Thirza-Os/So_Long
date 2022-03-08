#include "so_long.h"

int	check_position(int y, int x, t_program *program)
{
	if (x > 0 && x < (program->program_size->width / 80) && \
		(y > 0 && y < (program->program_size->height / 80)))
	{
		if (program->grid[y][x] == '0')
			return (1);
		if (program->grid[y][x] == 'C')
		{
			program->counter_collectables++;
			program->grid[y][x] = '0';
			return (1);
		}
		if (program->grid[y][x] == 'E' && program->counter_collectables == \
			program->max_collectables)
			exit (0);
	}
	return (0);
}

static int	ft_input(int key, void *param)
{
	t_program	*pr;

	pr = (t_program *)param;
	if (key == ESC)
		exit(0);
	if (key == RIGHT)
		right_move(pr);
	else if (key == LEFT)
		left_move(pr);
	else if (key == DOWN)
		down_move(pr);
	else if (key == UP)
		up_move(pr);
	make_game(&(*pr));
	mlx_put_image_to_window(pr->mlx, pr->window, pr->player->img_pointer, \
		pr->player_position->width * 80, pr->player_position->height * 80);
	return (0);
}

static int	close_window(void)
{
	exit (0);
}

void	put_player(t_program *program)
{
	program->counter_collectables = 0;
	mlx_put_image_to_window(program->mlx, program->window, \
		program->player->img_pointer, program->player_position->width * 80, \
		program->player_position->height * 80);
	mlx_key_hook(program->window, *ft_input, program);
	mlx_hook(program->window, 17, 0, close_window, program);
}

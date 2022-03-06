#include "so_long.h"

static int	check_position(int y, int x, t_program *program)
{
	// ft_printf("\ncollect: %d, \n max collect: %d\n", counter, program->max_collectables);
	if (x > 0 && x < (program->program_size->width / 80))
		if (y > 0 && y < (program->program_size->height / 80))
			if (program->grid[y][x] == '0')
				return (1);
	// if (program->grid[y][x] == 'C')
	// {
	// 	program->counter_collectables += 1;
	// 	program->grid[y][x] = '0';
	// 	return (1);
	// }
	// if (program->grid[y][x] == 'E' && program->counter_collectables == program->max_collectables)
	// 	exit(0);
	return (0);
}

static int	ft_input(int key, void *param)
{
	t_program	*pr;

	pr = (t_program *)param;
	if (key == ESC)
		exit(0);
	if (key == RIGHT)
	{
		if (check_position(pr->player_position->height, pr->player_position->width + 1, pr))
		{
			pr->player_position->width += 1;
			ft_printf("Key pressed -> %d\n", key);
		}
	}
	else if (key == LEFT)
	{
		if (check_position(pr->player_position->height, pr->player_position->width - 1, pr))
		{
			pr->player_position->width -= 1;
			ft_printf("Key pressed -> %d\n", key);
		}
	}
	else if (key == DOWN)
	{
		if (check_position(pr->player_position->height + 1, pr->player_position->width, pr))
		{
			pr->player_position->height += 1;
			ft_printf("Key pressed -> %d\n", key);
		}
	}
	else if (key == UP)
	{
		if (check_position(pr->player_position->height - 1, pr->player_position->width, pr))
		{
			pr->player_position->height -= 1;
			ft_printf("Key pressed -> %d\n", key);
		}
	}
	make_game(&(*pr));
	mlx_put_image_to_window(pr->mlx, pr->window, pr->player->img_pointer, \
		pr->player_position->width * 80, pr->player_position->height * 80);
	return (0);
}

void	put_player(t_program *program)
{
	// program->player_position->height = 1;
	// program->player_position->width = 1;
	// ft_printf("x: %d\n y: %d", program->player_position->width, program->player_position->height);
	mlx_put_image_to_window(program->mlx, program->window, \
		program->player->img_pointer, program->player_position->width * 80, \
		program->player_position->height * 80);
	mlx_key_hook(program->window, *ft_input, program);
}

#include "so_long.h"

static void	is_square(t_program *program)
{
	int	i;

	i = 0;
	while (program->grid[i + 1])
	{
		if (ft_strlen(program->grid[i]) != ft_strlen(program->grid[i + 1]))
			print_error("The map is not square");
		i++;
	}
}

static void	is_surrounded(t_program *program)
{
	int	i;
	int	x;
	int	y;
	int	loop;

	i = 0;
	y = 0;
	loop = 0;
	x = ft_strlen(program->grid[0]) - 1;
	while (program->grid[y + 1])
		y++;
	while (i <= y)
	{
		while (loop <= x)
		{
			if (i == 0 || i == y || loop == 0 || loop == x)
				if (program->grid[i][loop] != '1')
					print_error("The map is not surrounded by walls");
		loop++;
		}
	loop = 0;
	i++;
	}
}

void	validate_map(t_program *program)
{
	is_square(program);
	is_surrounded(program);
}

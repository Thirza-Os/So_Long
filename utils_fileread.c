#include "so_long.h"

void count_collectables(t_program *program, char *map_array)
{
	int	i;

	i = 0;
	program->max_collectables = 0;
	while (map_array[i])
	{
		if (map_array[i] == 'C')
			program->max_collectables++;
		i++;
	}
}

void	get_xy(t_program *program)
{
	program->max_xy = ft_malloc_check(malloc(sizeof(t_vector)));
	program->max_xy->height = 0;
	program->max_xy->width = ft_strlen(program->grid[0]);
	while (program->grid[program->max_xy->height])
		program->max_xy->height++;
	program->program_size = ft_malloc_check(malloc(sizeof(t_vector)));
	program->program_size->height = program->max_xy->height * 80;
	program->program_size->width = program->max_xy->width * 80;
}

void	parse_map(char *argv, t_program *program)
{
	char	*line;
	char	*map_array;
	int		i;
	int		fd;

	fd = (open(argv, O_RDONLY));
	if (fd < 0)
		ft_printf("Error\n File opening failed.\n");
	map_array = NULL;
	i = 0;
	while ((line = get_next_line(fd)))
	{
		map_array = ft_strjoin_free_so_long(map_array, line);
		line = NULL;
		i++;
	}
	free(line);
	close(fd);
	count_collectables(program, map_array);
	program->grid = (char **)malloc(sizeof(char *));
	program->grid = ft_split(map_array, '\n');
	free(map_array);
	get_xy(program);
}

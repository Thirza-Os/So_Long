#include "so_long.h"

void	count_collectables(t_program *program, char *map_array)
{
	int	i;
	int	count_exit;
	int	count_start;

	i = 0;
	count_exit = 0;
	count_start = 0;
	program->max_collectables = 0;
	while (map_array[i])
	{
		if (map_array[i] == 'C')
			program->max_collectables += 1;
		if (map_array[i] == 'E')
			count_exit++;
		if (map_array[i] == 'P')
			count_start++;
		if (map_array[i] != '0' && map_array[i] != '1' && \
			map_array[i] != 'E' && map_array[i] != 'C' && \
			map_array[i] != 'P' && map_array[i] != '\n')
			print_error("Unknown element!");
		i++;
	}
	if (count_exit < 1 || count_start < 1 || program->max_collectables < 1)
		print_error("Not enough elements!");
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
		print_error("File opening failed.");
	map_array = NULL;
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map_array = ft_strjoin_free_so_long(map_array, line);
		line = NULL;
		i++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	count_collectables(program, map_array);
	program->grid = ft_split(map_array, '\n');
	free(map_array);
	get_xy(program);
}

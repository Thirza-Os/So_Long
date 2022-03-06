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
	init_img(program, &program->exit, "./imgs/block_end.xpm");
	init_img(program, &program->wall, "./imgs/wall.xpm");
	init_img(program, &program->ground, "./imgs/empty_space.xpm");
	init_img(program, &program->dave, "./imgs/block_enemy.xpm");
}

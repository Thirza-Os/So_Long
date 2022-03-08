#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_program	program;

	if (argc == 2 && !check_ber(argv[1]))
	{
		program.mlx = mlx_init();
		parse_map(argv[1], &program); 
		validate_map(&program);
		load_imgs(&program);
		new_window(&program, program.program_size->width, \
			program.program_size->height, "THIRZAS WAY TO COOL GAME");
		make_game(&program);
		put_player(&program);
		mlx_loop(program.mlx);
	}
	else
		print_error("The arguments are not valid");
	return (0);
}

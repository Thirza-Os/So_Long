/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tosinga <tosinga@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 15:03:16 by tosinga       #+#    #+#                 */
/*   Updated: 2022/03/08 15:03:17 by tosinga       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_program	program;

	if (argc != 2 && check_ber(argv[1]))
		print_error("The arguments are not valid");
	program.mlx = mlx_init();
	parse_map(argv[1], &program);
	validate_map(&program);
	load_imgs(&program);
	new_window(&program, program.program_size->width, \
		program.program_size->height, "THIRZAS WAY TO COOL GAME");
	make_game(&program);
	put_player(&program);
	mlx_loop_hook(program.mlx, display_score, &program);
	mlx_loop(program.mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_moves.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tosinga <tosinga@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 15:03:13 by tosinga       #+#    #+#                 */
/*   Updated: 2022/03/08 15:03:14 by tosinga       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	right_move(t_program *program)
{
	if (check_position(program->player_position.height, \
		program->player_position.width + 1, program))
	{
		program->player_position.width += 1;
		program->key_presses += 1;
		program->player->img_pointer = program->player_two->img_pointer;
		ft_printf("Keys pressed -> %d\n", program->key_presses);
	}
}

void	left_move(t_program *program)
{
	if (check_position(program->player_position.height, \
		program->player_position.width - 1, program))
	{
		program->player_position.width -= 1;
		program->key_presses += 1;
		program->player->img_pointer = program->player_copy->img_pointer;
		ft_printf("Keys pressed -> %d\n", program->key_presses);
	}
}

void	down_move(t_program *program)
{
	if (check_position(program->player_position.height + 1, \
		program->player_position.width, program))
	{
		program->player_position.height += 1;
		program->key_presses += 1;
		ft_printf("Keys pressed -> %d\n", program->key_presses);
	}
}

void	up_move(t_program *program)
{
	if (check_position(program->player_position.height - 1, \
		program->player_position.width, program))
	{
		program->player_position.height -= 1;
		program->key_presses += 1;
		ft_printf("Keys pressed -> %d\n", program->key_presses);
	}
}

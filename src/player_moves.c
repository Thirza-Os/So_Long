/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_moves.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tosinga <tosinga@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 15:03:13 by tosinga       #+#    #+#                 */
/*   Updated: 2022/03/09 12:26:07 by tosinga       ########   odam.nl         */
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
	}
}

void	down_move(t_program *program)
{
	if (check_position(program->player_position.height + 1, \
		program->player_position.width, program))
	{
		program->player_position.height += 1;
		program->key_presses += 1;
	}
}

void	up_move(t_program *program)
{
	if (check_position(program->player_position.height - 1, \
		program->player_position.width, program))
	{
		program->player_position.height -= 1;
		program->key_presses += 1;
	}
}

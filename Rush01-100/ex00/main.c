/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 12:26:55 by trouchon          #+#    #+#             */
/*   Updated: 2020/09/20 17:50:54 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	int board[6][6];
	int solutions[24][4];
	int k;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (check_inputs(argv[1]) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	board_init_0(board);
	k = board_init_argv_lines(argv[1], board);
	board_init_argv_col(argv[1], board, k);
	init_big_tab(solutions);
	if (solve(board, solutions, 1) == 0)
		write(1, "Error\n", 6);
	return (0);
}

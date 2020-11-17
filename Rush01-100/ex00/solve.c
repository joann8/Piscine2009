/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 16:47:10 by jacher            #+#    #+#             */
/*   Updated: 2020/09/20 17:50:33 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	assign(int board[6][6], int big_tab[24][4], int row, int cmb)
{
	int i;

	i = 0;
	while (i < 4)
	{
		board[row][i + 1] = big_tab[cmb][i];
		i++;
	}
}

int		solve(int board[6][6], int big_tab[24][4], int row)
{
	int cmb;

	if (row == 5)
	{
		print(board);
		return (1);
	}
	cmb = -1;
	while (++cmb < 24)
	{
		assign(board, big_tab, row, cmb);
		if (line_is_valid_left(row, board) == 1
				&& line_is_valid_right(row, board) == 1
				&& columns_are_valid(row, board) == 1
				&& column_is_valid_up(row, board) == 1
				&& column_is_valid_down(row, board) == 1)
		{
			if (row < 5)
			{
				if (solve(board, big_tab, row + 1) == 1)
					return (1);
			}
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 11:36:01 by trouchon          #+#    #+#             */
/*   Updated: 2020/09/20 17:51:44 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	board_init_0(int board[6][6])
{
	int		i;
	int		j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
}

int		board_init_argv_lines(char *argv, int board[6][6])
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	j = 0;
	while (i < 6)
	{
		if (i == 0 || i == 5)
		{
			j = 1;
			while (j < 5)
			{
				board[i][j] = argv[k] - '0';
				k = k + 2;
				j++;
			}
		}
		i++;
	}
	return (k);
}

void	board_init_argv_col(char *argv, int board[6][6], int k)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < 6)
	{
		if (j == 0 || j == 5)
		{
			i = 1;
			while (i < 5)
			{
				board[i][j] = argv[k] - '0';
				i++;
				k = k + 2;
			}
		}
		j++;
	}
}

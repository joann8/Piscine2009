/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks_are_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 13:35:01 by trouchon          #+#    #+#             */
/*   Updated: 2020/09/20 17:51:11 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		line_is_valid_left(int row, int board[6][6])
{
	int max;
	int count;
	int i;

	count = 0;
	i = 1;
	max = 1;
	while (i < 5)
	{
		if (max <= board[row][i])
		{
			count++;
			max = board[row][i];
		}
		i++;
	}
	if (count != board[row][0])
		return (0);
	return (1);
}

int		line_is_valid_right(int row, int board[6][6])
{
	int max;
	int count;
	int i;

	max = 1;
	count = 0;
	i = 4;
	while (i > 0)
	{
		if (max <= board[row][i])
		{
			count++;
			max = board[row][i];
		}
		i--;
	}
	if (count != board[row][5])
		return (0);
	return (1);
}

int		columns_are_valid(int row, int board[6][6])
{
	int i;
	int j;

	j = 1;
	while (j < 5)
	{
		i = row - 1;
		while (i > 0)
		{
			if (board[row][j] == board[i][j])
				return (0);
			i--;
		}
		j++;
	}
	return (1);
}

int		column_is_valid_up(int row, int board[6][6])
{
	int max;
	int count;
	int i;
	int col;

	if (row < 4)
		return (1);
	col = 0;
	while (++col < 5)
	{
		i = 0;
		count = 0;
		max = 1;
		while (++i < 5)
		{
			if (max <= board[i][col])
			{
				count++;
				max = board[i][col];
			}
		}
		if (count != board[0][col])
			return (0);
	}
	return (1);
}

int		column_is_valid_down(int row, int board[6][6])
{
	int max;
	int count;
	int i;
	int col;

	if (row < 4)
		return (1);
	col = 0;
	while (++col < 5)
	{
		i = 5;
		count = 0;
		max = 1;
		while (--i > 0)
		{
			if (max <= board[i][col])
			{
				count++;
				max = board[i][col];
			}
		}
		if (count != board[5][col])
			return (0);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 10:24:58 by jacher            #+#    #+#             */
/*   Updated: 2020/09/16 20:25:49 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_check_rowcol(int row, int col, int tab[10][10])
{
	int i;

	i = 0;
	while (i < col)
	{
		if (tab[i][row] == 1)
			return (0);
		i++;
	}
	i = 0;
	return (1);
}

int		ft_check_diag(int row, int col, int tab[10][10])
{
	int i;
	int j;

	i = col - 1;
	j = row - 1;
	while (j >= 0 && i >= 0)
	{
		if (tab[i][j] == 1)
			return (0);
		i--;
		j--;
	}
	i = col - 1;
	j = row + 1;
	while (i >= 0 && j <= 9)
	{
		if (tab[i][j] == 1)
			return (0);
		i--;
		j++;
	}
	return (1);
}

void	ft_print(int tab[10][10], int *ptr)
{
	int		i;
	int		j;
	char	c;
	int		ct;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (tab[i][j] == 1)
			{
				c = j + 48;
				write(1, &c, 1);
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
	ct = *ptr;
	*ptr = ct + 1;
}

int		ft_placement(int col, int tab[10][10], int *ptr)
{
	int line;

	line = 0;
	while (line < 10)
	{
		tab[col][line] = 1;
		if ((ft_check_rowcol(line, col, tab) == 1)
				&& (ft_check_diag(line, col, tab) == 1))
		{
			if (col < 9)
				ft_placement(col + 1, tab, ptr);
			else
				ft_print(tab, ptr);
		}
		tab[col][line] = 0;
		line++;
	}
	return (*ptr);
}

int		ft_ten_queens_puzzle(void)
{
	int tab[10][10];
	int count;
	int *ptr;
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
	count = 0;
	ptr = &count;
	return (ft_placement(0, tab, ptr));
}

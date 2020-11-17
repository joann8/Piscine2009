/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab24-4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 09:53:42 by jacher            #+#    #+#             */
/*   Updated: 2020/09/20 17:52:32 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_rec(int tab[4], int *count, int big_tab[24][4])
{
	int i;
	int a;

	a = *count;
	i = 0;
	while (i < 4)
	{
		big_tab[a][i] = tab[i];
		i++;
	}
	*count = a + 1;
}

int		check(int tab[4], int col, int k)
{
	int i;

	i = col - 1;
	while (i >= 0)
	{
		if (tab[i] == k)
			return (0);
		i--;
	}
	return (1);
}

void	placement(int tab[4], int col, int *count, int big_tab[24][4])
{
	int k;

	k = 1;
	while (k <= 4)
	{
		tab[col] = k;
		if ((check(tab, col, k) == 1))
		{
			if (col < 3)
				placement(tab, col + 1, count, big_tab);
			else
			{
				print_rec(tab, count, big_tab);
			}
		}
		tab[col] = 0;
		k++;
	}
}

void	init_big_tab(int big_tab[24][4])
{
	int tab[4];
	int *count;
	int a;

	a = 0;
	count = &a;
	placement(tab, 0, count, big_tab);
}

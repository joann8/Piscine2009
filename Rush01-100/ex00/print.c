/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 11:53:06 by trouchon          #+#    #+#             */
/*   Updated: 2020/09/20 17:55:42 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print(int board[6][6])
{
	int		i;
	int		j;
	char	c;

	i = 1;
	while (i < 5)
	{
		j = 1;
		while (j < 5)
		{
			c = board[i][j] + '0';
			write(1, &c, 1);
			if (j != 4)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

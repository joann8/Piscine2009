/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 12:09:07 by jacher            #+#    #+#             */
/*   Updated: 2020/09/09 12:33:12 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar_3(char a, char b, char c);

void		ft_putchar_2(char d, char e);

void		ft_print_comb(void)
{
	int i;
	int j;
	int k;

	i = 48;
	while (i < 56)
	{
		j = i + 1;
		while (j < 57)
		{
			k = j + 1;
			while (k < 58)
			{
				ft_putchar_3(i, j, k);
				k++;
				if (i + j + k < 169)
					ft_putchar_2(',', ' ');
			}
			j++;
		}
		i++;
	}
}

void		ft_putchar_3(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
}

void		ft_putchar_2(char d, char e)
{
	write(1, &d, 1);
	write(1, &e, 1);
}

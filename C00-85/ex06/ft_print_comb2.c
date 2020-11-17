/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 12:35:09 by jacher            #+#    #+#             */
/*   Updated: 2020/09/09 13:32:53 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c);

void		ft_int_into_char(int x);

void		ft_print_comb2(void)
{
	int	i;
	int j;

	i = 0;
	while (i < 99)
	{
		j = i + 1;
		while (j < 100)
		{
			ft_int_into_char(i);
			ft_putchar(' ');
			ft_int_into_char(j);
			if (i + j < 197)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			j++;
		}
		i++;
	}
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_int_into_char(int x)
{
	char	l1;
	char	l2;
	int		a;
	int		b;

	a = x / 10;
	b = x % 10;
	l1 = a + 48;
	l2 = b + 48;
	write(1, &l1, 1);
	write(1, &l2, 1);
}

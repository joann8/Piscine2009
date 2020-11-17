/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 14:06:31 by jacher            #+#    #+#             */
/*   Updated: 2020/09/17 14:17:08 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		print_0(int nb, int lim, int tour)
{
	int num;

	if (tour == 1)
		write(1, ", ", 2);
	num = lim / 10;
	while (nb / num == 0)
	{
		write(1, "0", 1);
		num = num / 10;
	}
}

void		ft_print(int nb, int lim)
{
	char c;

	if (nb >= 10)
	{
		ft_print((nb / 10), lim);
	}
	c = (nb % 10) + 48;
	write(1, &c, 1);
}

int			limit_max(int n)
{
	int i;
	int limit;

	i = 1;
	limit = 1;
	while (i <= n)
	{
		limit = limit * 10;
		i++;
	}
	return (limit);
}

int			ft_check(int nb, int lim)
{
	if (nb < lim)
		lim = lim / 10;
	while (lim >= 10)
	{
		if ((nb / lim) >= ((nb % lim) / (lim / 10)))
			return (0);
		nb = nb % lim;
		lim = lim / 10;
	}
	return (1);
}

void		ft_print_combn(int n)
{
	int i;
	int tour;
	int num;

	tour = 0;
	i = -1;
	num = 0;
	if (n == 1)
		write(1, "0, 1, 2, 3, 4, 5, 6, 7, 8, 9", 28);
	else
	{
		while (++i < n)
			num = num * 10 + i;
		while (num < limit_max(n) && num < 123456790)
		{
			if (ft_check(num, limit_max(n)) == 1)
			{
				print_0(num, limit_max(n), tour);
				ft_print(num, limit_max(n));
				tour = 1;
			}
			num++;
		}
	}
}

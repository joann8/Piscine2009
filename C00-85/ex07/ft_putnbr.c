/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 14:06:08 by jacher            #+#    #+#             */
/*   Updated: 2020/09/17 14:29:54 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c);

void		ft_putnbr(int nb)
{
	unsigned int	nbr2;
	unsigned char	c;

	if (nb < 0)
	{
		ft_putchar('-');
		nbr2 = -nb;
	}
	else
		nbr2 = nb;
	if (nbr2 >= 10)
		ft_putnbr(nbr2 / 10);
	c = (nbr2 % 10) + 48;
	ft_putchar(c);
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

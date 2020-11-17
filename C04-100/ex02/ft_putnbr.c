/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 13:04:10 by jacher            #+#    #+#             */
/*   Updated: 2020/09/14 12:12:17 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	unsigned int num;

	if (nb < 0)
	{
		write(1, "-", 1);
		num = nb * (-1);
	}
	else
		num = nb;
	if (num > 9)
		ft_putnbr(num / 10);
	num = (num % 10) + 48;
	write(1, &num, 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 21:17:21 by jacher            #+#    #+#             */
/*   Updated: 2020/09/11 13:24:47 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_base_change(unsigned int nb)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb < 16)
	{
		write(1, "0", 1);
		write(1, &base[nb], 1);
	}
	else
	{
		write(1, &base[nb / 16], 1);
		write(1, &base[nb % 16], 1);
	}
}

void		ft_putstr_non_printable(char *str)
{
	unsigned int	i;
	unsigned int	temp;
	unsigned char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = (unsigned char)str[i];
		temp = c;
		if ((c < 32) || (c > 126))
		{
			write(1, "\\", 1);
			ft_base_change(temp);
		}
		else
			write(1, &c, 1);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 21:51:09 by jacher            #+#    #+#             */
/*   Updated: 2020/10/01 09:40:46 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putnbr(unsigned long nb)
{
	unsigned char	c;
	char			*base;

	base = "0123456789abcdef";
	if (nb >= 16)
		ft_putnbr(nb / 16);
	c = base[nb % 16];
	write(1, &c, 1);
}

void		ft_put_addr(long nb)
{
	int				count;
	unsigned long	nbr2;

	if (nb < 0)
		nbr2 = -nb;
	else
		nbr2 = nb;
	count = 1;
	while (nbr2 / 16 > 15)
	{
		count++;
		nbr2 = nbr2 / 16;
	}
	while (16 - count > 0)
	{
		write(1, "0", 1);
		count++;
	}
	if (nb < 0)
		nbr2 = -nb;
	else
		nbr2 = nb;
	ft_putnbr(nbr2);
	write(1, ": ", 2);
}

void		ft_put_char(unsigned char car, int j)
{
	unsigned long	nbr2;
	unsigned char	c;
	char			*base;

	nbr2 = car;
	base = "0123456789abcdef";
	if (nbr2 <= 16)
	{
		write(1, "0", 1);
		c = base[nbr2 % 16];
		write(1, &c, 1);
	}
	else
	{
		c = base[nbr2 / 16];
		write(1, &c, 1);
		c = base[nbr2 % 16];
		write(1, &c, 1);
	}
	if (j % 2 == 1)
		write(1, " ", 1);
}

void		finish(char *str, int j, int size)
{
	int		count;

	if (size <= 0)
		return ;
	ft_put_addr((long)(str));
	count = 16;
	while (str[++j] != '\0')
		ft_put_char(str[j], j);
	count = count - j - 1;
	if (j % 2 == 1 && count--)
		write(1, "00 ", 3);
	while (count-- > 0)
		if (count % 2 == 0)
			write(1, "     ", 5);
	j = -1;
	while (str[++j] != '\0')
	{
		if (str[j] >= 32 && str[j] <= 126)
			write(1, &str[j], 1);
		else
			write(1, ".", 1);
	}
	write(1, "\n", 1);
}

void		*ft_print_memory(void *addr, unsigned int size)
{
	int		j;
	int		index;
	char	*str;

	str = (char *)addr;
	index = 0;
	while (size > 15 && ((size = size - 16) > 0))
	{
		ft_put_addr(((long)(addr + index)));
		j = -1;
		while (++j < 16)
			ft_put_char(str[index + j], j);
		j = -1;
		while (++j < 16)
		{
			if (str[index + j] >= 32 && str[index + j] <= 126)
				write(1, &str[index + j], 1);
			else
				write(1, ".", 1);
		}
		write(1, "\n", 1);
		index = index + 16;
	}
	finish(&str[index], -1, size);
	return (addr);
}

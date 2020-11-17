/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 21:04:39 by jacher            #+#    #+#             */
/*   Updated: 2020/09/20 12:50:59 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_check_char(char c, char *base);
int		ft_check_base(char *base);

void	ft_putnbr_base(int nb, int size_to, char *base_to, char *tab)
{
	int				i;
	unsigned int	nbr;

	i = 0;
	if (nb < 0)
		nbr = -nb;
	else
		nbr = nb;
	while (nbr / size_to > 0)
	{
		tab[i] = base_to[(nbr % size_to)];
		i++;
		nbr = nbr / size_to;
	}
	tab[i] = base_to[(nbr % size_to)];
	if (nb < 0)
	{
		tab[i + 1] = '-';
		i++;
	}
	tab[i + 1] = '\0';
}

int		table_size(int nb, int size_to)
{
	int				count;
	unsigned int	nbr;

	count = 1;
	if (nb < 0)
	{
		nbr = -nb;
		count++;
	}
	else
		nbr = nb;
	while ((nbr / size_to) > 0)
	{
		count++;
		nbr = nbr / size_to;
	}
	return (count + 1);
}

int		initialisation(char *nbr, int size_from, char *base_from)
{
	int		i;
	int		num;
	int		sign;

	i = 0;
	num = 0;
	while (nbr[i] == ' ' || (nbr[i] >= '\t' && nbr[i] <= '\r'))
		i++;
	sign = 1;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (ft_check_char(nbr[i], base_from) >= 0)
	{
		num = num * size_from + ft_check_char(nbr[i], base_from);
		i++;
	}
	return (num * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	int		num;
	char	*tab;
	char	*temp;
	int		size_tab;

	if (ft_check_base(base_from) == 0 || ft_check_base(base_to) == 0)
		return (0);
	num = initialisation(nbr, ft_check_base(base_from), base_from);
	size_tab = table_size(num, ft_check_base(base_to));
	if (!(tab = malloc(sizeof(char) * (size_tab))))
		return (0);
	ft_putnbr_base(num, ft_check_base(base_to), base_to, tab);
	if (!(temp = malloc(sizeof(char) * (size_tab))))
		return (0);
	i = 0;
	while (i < size_tab - 1)
	{
		temp[i] = tab[size_tab - i - 2];
		i++;
	}
	temp[i] = '\0';
	free(tab);
	return (temp);
}

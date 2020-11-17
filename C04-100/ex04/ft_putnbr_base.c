/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 19:02:25 by jacher            #+#    #+#             */
/*   Updated: 2020/09/15 14:30:13 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int				ft_base_check(char *base)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	if (i == 1 || i == 0)
		return (0);
	return (1);
}

void			ft_affiche(unsigned int num, unsigned int taille, char *base)
{
	if (num < taille)
		write(1, &base[num], 1);
	else
	{
		ft_affiche((num / taille), taille, base);
		write(1, &base[(num % taille)], 1);
	}
}

void			ft_putnbr_base(int nbr, char *base)
{
	unsigned int	num;
	unsigned int	taille;

	if (base == NULL || ft_base_check(base) == 0)
		return ;
	taille = ft_strlen(base);
	if (nbr < 0)
	{
		write(1, "-", 1);
		num = nbr * (-1);
	}
	else
		num = nbr;
	ft_affiche(num, taille, base);
}

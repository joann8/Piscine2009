/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:35:02 by jacher            #+#    #+#             */
/*   Updated: 2020/09/21 18:18:53 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

void					ft_strcopy(char *src, char *dest)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

struct s_stock_str		*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	int			j;
	t_stock_str *tab;

	if (!(tab = malloc(sizeof(t_stock_str) * (ac + 1))))
		return (NULL);
	i = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
			j++;
		tab[i].size = j;
		tab[i].str = av[i];
		if ((!(tab[i].copy = malloc(sizeof(char) * (j + 1)))))
			return (NULL);
		ft_strcopy(av[i], tab[i].copy);
		i++;
	}
	tab[i].str = 0;
	tab[i].size = 0;
	tab[i].copy = 0;
	return (tab);
}

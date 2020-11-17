/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 11:40:49 by jacher            #+#    #+#             */
/*   Updated: 2020/09/20 17:00:32 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		check_char(char str, char *charset)
{
	int i;

	i = 0;
	while (charset[i] != 0)
	{
		if (str == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		c_sep(char *str, char *charset)
{
	int		count;
	int		i;
	int		check;

	i = 0;
	count = 0;
	check = 0;
	while (str[i] != '\0')
	{
		while (check_char(str[i], charset) == 0 && str[i] != '\0')
		{
			i++;
			check = 1;
		}
		while (check_char(str[i], charset) == 1 && str[i] != '\0')
			i++;
		if (check == 1)
			count++;
	}
	return (count + 1);
}

int		print(int index, int i, char *str, char *tab_k)
{
	int j;

	j = 0;
	while (j < i - index)
	{
		tab_k[j] = str[index + j];
		j++;
	}
	tab_k[j] = '\0';
	return (1);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		k;
	int		index;

	if ((!(tab = malloc(sizeof(char*) * c_sep(str, charset)))))
		return (0);
	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		index = i;
		while (check_char(str[i], charset) == 0 && str[i] != '\0')
			i++;
		if (i > 0)
		{
			if (!(tab[k] = malloc(sizeof(char) * (i - index + 1))))
				return (0);
			k = print(index, i, str, tab[k]) + k;
		}
		while (check_char(str[i], charset) == 1 && str[i] != '\0')
			i++;
	}
	tab[k] = NULL;
	return (tab);
}

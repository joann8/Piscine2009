/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 19:29:25 by jacher            #+#    #+#             */
/*   Updated: 2020/09/20 12:31:37 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_len(int size, char **strs, char *sep)
{
	int i;
	int j;
	int k;
	int count;

	k = 0;
	while (sep[k] != '\0')
		k++;
	count = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			count++;
			j++;
		}
		count = count + k;
		i++;
	}
	return (count - k + 1);
}

int			copy(char *s1, char *temp, int k)
{
	int j;

	j = 0;
	while (s1[j] != '\0')
	{
		temp[k] = s1[j];
		k++;
		j++;
	}
	return (k);
}

char		*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		k;
	char	*temp;

	if (size == 0)
	{
		if (!(temp = malloc(sizeof(char))))
			return (0);
		temp[0] = '\0';
		return (temp);
	}
	if (!(temp = malloc(sizeof(char) * ft_len(size, strs, sep))))
		return (0);
	i = 0;
	k = 0;
	while (i < size)
	{
		k = copy(strs[i], temp, k);
		if (i < size - 1)
			k = copy(sep, temp, k);
		i++;
	}
	temp[k] = '\0';
	return (temp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 15:38:02 by jacher            #+#    #+#             */
/*   Updated: 2020/09/20 11:31:43 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int	i;
	int *temp;

	if (min >= max)
	{
		temp = NULL;
		return (temp);
	}
	if (!(temp = malloc(sizeof(min) * (max - min))))
		return (NULL);
	i = 0;
	while (min + i < max)
	{
		temp[i] = min + i;
		i++;
	}
	return (temp);
}

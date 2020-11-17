/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 16:08:26 by jacher            #+#    #+#             */
/*   Updated: 2020/09/20 16:31:11 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int *temp;

	if (min >= max)
		return (0);
	if (!(temp = malloc(sizeof(int) * (max - min))))
		return (-1);
	i = 0;
	while (min + i < max)
	{
		temp[i] = min + i;
		i++;
	}
	*range = temp;
	return (max - min);
}

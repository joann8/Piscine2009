/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 09:16:49 by jacher            #+#    #+#             */
/*   Updated: 2020/09/16 17:14:46 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;
	int test;

	i = 0;
	test = 0;
	if (nb == 1)
		return (1);
	if (nb > 1)
	{
		while ((i * i <= nb) && i <= 46340)
		{
			test = i * i;
			if (test == nb)
				return (i);
			i++;
		}
	}
	return (0);
}

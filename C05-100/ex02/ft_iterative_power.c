/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 21:05:07 by jacher            #+#    #+#             */
/*   Updated: 2020/09/16 16:59:54 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int num;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	num = 1;
	while (power > 0)
	{
		num = num * nb;
		power--;
	}
	return (num);
}

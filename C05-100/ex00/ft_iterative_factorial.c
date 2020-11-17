/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 18:49:03 by jacher            #+#    #+#             */
/*   Updated: 2020/09/16 16:58:30 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int	temp;

	if (nb > -1)
	{
		temp = 1;
		while (nb > 0)
		{
			temp = temp * nb;
			nb--;
		}
	}
	else
		temp = 0;
	return (temp);
}

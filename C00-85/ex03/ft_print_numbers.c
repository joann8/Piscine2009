/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 11:55:22 by jacher            #+#    #+#             */
/*   Updated: 2020/09/09 12:00:15 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c);

void		ft_print_numbers(void)
{
	int i;

	i = 48;
	while (i <= 57)
	{
		ft_putchar(i);
		i++;
	}
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

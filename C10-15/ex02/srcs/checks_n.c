/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:55:36 by jacher            #+#    #+#             */
/*   Updated: 2020/09/28 14:50:30 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tail.h"

void	print_name(char *name)
{
	int		i;

	write(1, "==> ", 4);
	i = 0;
	while (name[i] != '\0')
		i++;
	write(1, name, i);
	write(1, " <==\n", 5);
}

int		check_n(char *str)
{
	int i;
	int num;

	i = 0;
	num = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		num = num * 10 + str[i] - 48;
		i++;
	}
	return (num);
}

int		find_n(char **av, int *ptr)
{
	if (av[1][0] == '-')
	{
		if (av[1][1] == 'c')
		{
			if (av[1][2] == '\0')
			{
				if (check_n(av[2]) >= 0)
				{
					*ptr = 3;
					return (check_n(av[2]));
				}
			}
			else
			{
				if (check_n(av[1] + 2) >= 0)
				{
					*ptr = 2;
					return (check_n(av[1] + 2));
				}
			}
		}
	}
	return (-1);
}

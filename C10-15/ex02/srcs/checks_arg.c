/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:41:32 by jacher            #+#    #+#             */
/*   Updated: 2020/09/30 11:16:02 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tail.h"

int		check_arg_one(void)
{
	char	buf[500];
	int		a;

	while (read(0, buf, 500) > 0)
		a = 1;
	return (0);
}

int		check_arg_two(int ac, char **av)
{
	char	buf[500];
	int		b_read;
	int		i;
	int		a;

	if (av[1][2] == '\0')
		print_error_arg();
	else
	{
		i = 2;
		while (av[1][i] >= '0' && av[1][i] <= '9')
			i++;
		if (av[1][i] == '\0')
			while ((b_read = read(0, buf, 500)) > 0)
				a = 1;
		else
			print_error_option(ac, av[1]);
	}
	return (0);
}

int		check_arg_three(int ac, char **av)
{
	int		i;
	char	buf[500];
	int		b_read;
	int		a;

	i = 0;
	while (av[2][i] >= '0' && av[2][i] <= '9')
		i++;
	if (i == 0)
	{
		print_error_option(3, av[2]);
		return (0);
	}
	if (av[2][i] == '\0')
	{
		if (ac == 3)
			while ((b_read = read(0, buf, 500)) > 0)
				a = 1;
		else
			return (1);
	}
	return (1);
}

int		check_arg(int ac, char **av)
{
	int		i;
	int		value;

	value = 0;
	if (ac == 1)
		value = check_arg_one();
	else if (ac == 2)
		value = check_arg_two(ac, av);
	else if (ac >= 3)
	{
		if (av[1][2] == '\0')
			value = check_arg_three(ac, av);
		else
		{
			i = 2;
			while (av[1][i] >= '0' && av[1][i] <= '9')
				i++;
			if (av[1][i] == '\0')
				value = 1;
			else
				print_error_option(2, av[1]);
		}
	}
	return (value);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:25:03 by jacher            #+#    #+#             */
/*   Updated: 2020/09/30 11:15:07 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tail.h"

void	print_error_arg(void)
{
	write(2, "tail: option requires an argument -- c\n", 39);
	write(2, "usage: tail [-F | -f | -r] [-q] ", 32);
	write(2, "[-b # | -c # | -n #] [file ...]\n", 32);
}

void	print_error_option(int ac, char *av)
{
	int i;

	write(2, "tail: illegal offset -- ", 24);
	if (ac == 2)
	{
		i = 2;
		while (av[i] != '\0')
			i++;
		write(2, av + 2, i - 2);
	}
	else
	{
		i = 0;
		while (av[i] != '\0')
			i++;
		write(2, av, i);
	}
	write(2, "\n", 1);
}

void	print_error(int errnum, char *name)
{
	int		i;
	char	*s;

	write(2, "tail: ", 6);
	i = 0;
	while (name[i] != '\0')
		i++;
	write(2, name, i);
	write(2, ": ", 2);
	s = strerror(errnum);
	i = 0;
	while (s[i] != '\0')
	{
		write(2, &s[i], 1);
		i++;
	}
	write(2, "\n", 1);
}

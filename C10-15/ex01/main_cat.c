/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:08:22 by jacher            #+#    #+#             */
/*   Updated: 2020/09/30 10:19:56 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		main(int ac, char **av)
{
	int		i;
	char	buf[4096];
	int		bytes;

	if (ac == 1)
	{
		while ((bytes = read(0, buf, 4096)) > 0)
			write(0, buf, bytes);
		return (0);
	}
	i = 1;
	while (i < ac)
	{
		if ((av[i][0] == '-' && av[i][1] == '\0'))
		{
			while ((bytes = read(0, buf, 4096)) > 0)
				write(0, buf, bytes);
			return (0);
		}
		if (check_slash(av[i]) != 1)
			read_file(av[i]);
		i++;
	}
	return (0);
}

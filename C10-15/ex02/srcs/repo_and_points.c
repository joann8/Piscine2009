/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repo_and_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 11:57:17 by jacher            #+#    #+#             */
/*   Updated: 2020/09/30 11:13:05 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_tail.h"

int		check_slash_points(char *av, int start, int ac, int pos)
{
	int i;

	i = 0;
	while (av[i] != '\0')
	{
		if (av[i] == '.' || av[i] == '/')
			i++;
		else
			break ;
	}
	if (av[i] == '\0' && i != 0)
	{
		if (pos != start)
			write(1, "\n", 1);
		if (ac != start + 1)
			print_name(av);
		return (0);
	}
	return (1);
}

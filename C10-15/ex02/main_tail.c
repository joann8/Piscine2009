/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:55:36 by jacher            #+#    #+#             */
/*   Updated: 2020/09/30 11:17:14 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	cat(int fd, char *av, int n, int diff)
{
	char	buf[4096];
	int		offset;
	int		bytes;
	char	c;

	bytes = 0;
	offset = -1;
	while ((bytes = (read(fd, buf, 4096))) > 0)
		offset = offset + bytes;
	if (close(fd) == -1)
		print_error(errno, av);
	if (diff > 1)
		print_name(av);
	fd = open(av, O_RDONLY);
	while (read(fd, &c, 1) > 0)
	{
		if (offset < n)
			write(1, &c, 1);
		offset--;
	}
	if (close(fd) == -1)
		print_error(errno, av);
}

void	run_tail(int ac, char **av, int i, int n)
{
	int		start;
	int		check;
	int		fd;

	check = 0;
	start = i;
	while (i < ac)
	{
		if ((check_slash_points(av[i], start, ac, i) == 0))
			check = 1;
		else
		{
			fd = open(av[i], O_RDONLY);
			if (fd == -1)
				print_error(errno, av[i]);
			else
			{
				if (i != start && ac - i > 0 && check == 1)
					write(1, "\n", 1);
				check = 1;
				cat(fd, av[i], n, ac - start);
			}
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	int	i;
	int	n;

	n = 0;
	if (check_arg(ac, av) == 0)
		return (0);
	if (find_n(av, &i) < 0)
	{
		print_error(errno, "");
		return (0);
	}
	else
		n = find_n(av, &i);
	run_tail(ac, av, i, n);
	return (0);
}

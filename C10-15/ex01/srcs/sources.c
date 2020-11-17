/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:08:22 by jacher            #+#    #+#             */
/*   Updated: 2020/09/30 10:05:31 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

void	print_name(char *name)
{
	char	*n;
	int		i;

	n = basename(name);
	i = 0;
	while (n[i] != '\0')
	{
		write(2, &n[i], 1);
		i++;
	}
	write(2, ": ", 2);
}

void	print_error(int errnum, char *name)
{
	int		i;
	char	*s;

	write(2, "cat: ", 5);
	print_name(name);
	s = strerror(errnum);
	i = 0;
	while (s[i] != '\0')
	{
		write(2, &s[i], 1);
		i++;
	}
	write(2, "\n", 1);
}

int		check_directory(char *av)
{
	int i;

	i = 0;
	while (av[i] != '\0')
	{
		if (av[i] == '/' || av[i] == '.')
			break ;
		i++;
	}
	if (av[i] != '\0')
	{
		write(2, "cat: ", 5);
		i = 0;
		while (av[i] != '\0')
		{
			write(1, &av[i], 1);
			i++;
		}
		write(2, ": No such file or directory\n", 28);
		return (1);
	}
	return (0);
}

int		check_slash(char *av)
{
	int i;

	i = 0;
	while (av[i] != '\0')
	{
		if (av[i] == '/' || av[i] == '.')
			i++;
		else
			break ;
	}
	if (av[i] == '\0')
	{
		write(2, "cat: ", 5);
		i = 0;
		while (av[i] != '\0')
		{
			write(2, &av[i], 1);
			i++;
		}
		write(2, ": Is a directory\n", 17);
		return (1);
	}
	return (0);
}

void	read_file(char *av)
{
	int		fd;
	char	buf[4096];
	int		bytes;

	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		if (check_directory(av) == 0)
			print_error(errno, av);
	}
	else
	{
		while ((bytes = read(fd, buf, 4096)) > 0)
			write(1, buf, bytes);
		if (close(fd) == -1)
			print_error(errno, av);
	}
}

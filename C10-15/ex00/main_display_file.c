/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 18:49:19 by jacher            #+#    #+#             */
/*   Updated: 2020/09/30 09:46:24 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	int		f_to_read;
	char	buf[500];
	int		bytes;

	if (ac == 1)
		write(2, "File name missing.\n", 19);
	else if (ac > 2)
		write(2, "Too many arguments.\n", 20);
	else
	{
		f_to_read = open(av[1], O_RDONLY);
		if (f_to_read == -1)
		{
			write(2, "Cannot read file.\n", 18);
			return (1);
		}
		else
			while (((bytes = read(f_to_read, buf, 500)) > 0))
				write(1, buf, bytes);
		close(f_to_read);
	}
	return (0);
}

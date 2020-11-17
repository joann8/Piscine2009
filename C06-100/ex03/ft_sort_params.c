/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:00:28 by jacher            #+#    #+#             */
/*   Updated: 2020/09/15 18:31:50 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	unsigned char	car1;
	unsigned char	car2;
	unsigned int	i;

	i = 0;
	while ((s1[i] != '\0') || s2[i] != '\0')
	{
		car1 = (unsigned char)s1[i];
		car2 = (unsigned char)s2[i];
		if ((car1 - car2) != 0)
			return (car1 - car2);
		i++;
	}
	car1 = (unsigned char)s1[i];
	car2 = (unsigned char)s2[i];
	return (car1 - car2);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_params(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			ft_putchar(argv[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*temp;

	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
			{
				temp = argv[i];
				argv[i] = argv[j];
				argv[j] = temp;
			}
			j++;
		}
		i++;
	}
	ft_print_params(argc, argv);
	return (0);
}

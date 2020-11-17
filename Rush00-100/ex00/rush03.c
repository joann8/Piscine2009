/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 12:29:08 by jurichar          #+#    #+#             */
/*   Updated: 2020/09/12 19:31:25 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int col, int ln)
{
	int i;
	int j;

	i = 0;
	if (col < 1 || ln < 1)
		return ;
	while (i < ln)
	{
		j = 0;
		while (j < col)
		{
			if ((j == 0 && i == 0) || (j == 0 && i == ln - 1))
				ft_putchar('A');
			else if ((j == col - 1 && i == 0) || (j == col - 1 && i == ln - 1))
				ft_putchar('C');
			else if (i == 0 || j == 0 || j == col - 1 || i == ln - 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

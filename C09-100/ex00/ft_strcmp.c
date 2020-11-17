/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 14:11:21 by jacher            #+#    #+#             */
/*   Updated: 2020/09/14 09:14:11 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

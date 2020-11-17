/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 13:12:17 by jacher            #+#    #+#             */
/*   Updated: 2020/09/13 18:59:21 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_isspace3(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' ||
			c == '\r' || c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}

int		ft_atoi(char *str)
{
	int	i;
	int sign;
	int temp;

	i = 0;
	while (ft_is_isspace3(str[i]) == 1)
		i++;
	sign = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	temp = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = temp * 10 + str[i] - 48;
		i++;
	}
	return (temp * sign);
}

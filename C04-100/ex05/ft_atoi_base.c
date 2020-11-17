/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 14:57:02 by jacher            #+#    #+#             */
/*   Updated: 2020/09/15 14:21:05 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int				ft_base_str_check(char *str, char *base)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	if (ft_strlen(str) == 0 || ft_strlen(base) == 0 || ft_strlen(base) == 1)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
				|| (base[i] >= '\t' && base[i] <= '\r'))
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int				ft_char_check(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int				ft_atoi_base(char *str, char *base)
{
	int	taille;
	int	sign;
	int	i;
	int	temp;

	if (base == 0 || ft_base_str_check(str, base) == 0)
		return (0);
	taille = ft_strlen(base);
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	sign = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	temp = 0;
	while (ft_char_check(str[i], base) >= 0)
	{
		temp = temp * taille + ft_char_check(str[i], base);
		i++;
	}
	return (temp * sign);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 10:47:25 by jacher            #+#    #+#             */
/*   Updated: 2020/09/14 09:48:12 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_analyse(char *str, char *to_find, unsigned int i, int size_f)
{
	int		j;
	char	*temp;

	j = 0;
	temp = str + i;
	while (((str[i] != '\0') && (to_find[j] != '\0')))
	{
		if (str[i + j] != to_find[j])
		{
			temp = 0;
			return (temp);
		}
		j++;
	}
	if (j == size_f)
		return (temp);
	else
	{
		temp = 0;
		return (temp);
	}
}

char	*ft_strstr(char *str, char *to_find)
{
	int				i;
	char			*temp;
	int				size_f;

	i = 0;
	if (to_find[i] == '\0')
		return (str);
	size_f = 0;
	while (to_find[size_f] != '\0')
		size_f++;
	temp = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
			temp = ft_analyse(str, to_find, i, size_f);
		if (temp != 0)
			break ;
		i++;
	}
	return (temp);
}

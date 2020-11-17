/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacher <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 10:28:31 by jacher            #+#    #+#             */
/*   Updated: 2020/09/14 10:50:49 by jacher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void			ft_cpy_mano(char *dest, char *src, const unsigned int dst_len)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[dst_len + i] = src[i];
		i++;
	}
	dest[dst_len + i] = src[i];
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int		i;
	const unsigned int	dst_len = ft_strlen(dest);
	const unsigned int	src_len = ft_strlen(src);

	i = 0;
	if (dst_len >= size)
		return (src_len + size);
	if (src_len + dst_len < size)
		ft_cpy_mano(dest, src, dst_len);
	else if (src_len + dst_len >= size)
	{
		while (i < size - dst_len - 1 && src[i] != '\0')
		{
			dest[dst_len + i] = src[i];
			i++;
		}
		dest[dst_len + i] = '\0';
	}
	return (src_len + dst_len);
}

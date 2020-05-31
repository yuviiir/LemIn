/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysharma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 06:53:28 by ysharma           #+#    #+#             */
/*   Updated: 2019/06/11 17:02:50 by ysharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*source;
	char	*dest;
	int		i;
	int		j;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	j = (int)len;
	source = (char *)src;
	dest = (char *)dst;
	if (source <= dest)
		while (j > 0)
		{
			dest[j - 1] = source[j - 1];
			j--;
		}
	else
		while (j > i)
		{
			dest[i] = source[i];
			i++;
		}
	return (dst);
}

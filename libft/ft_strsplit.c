/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysharma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 07:07:26 by ysharma           #+#    #+#             */
/*   Updated: 2019/07/10 18:25:38 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_args(char *raw, char delim)
{
	int	count;

	count = 0;
	while (*raw)
	{
		if (*raw != delim && (*(raw + 1) == delim || !*(raw + 1)))
			++count;
		++raw;
	}
	return (count);
}

char		**ft_strsplit(char *raw, char delim)
{
	char	**arr;
	int		size;
	int		i;

	size = count_args(raw, delim);
	if (!(arr = ft_memalloc(sizeof(char *) * (size + 1))))
		return (arr);
	i = 0;
	while (*raw)
	{
		while (*raw && *raw == delim)
			*raw++ = '\0';
		if (*raw)
			arr[i++] = raw;
		while (*raw && *raw != delim)
			++raw;
	}
	return (arr);
}
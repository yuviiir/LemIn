/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysharma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 10:25:20 by ysharma           #+#    #+#             */
/*   Updated: 2019/06/10 06:53:05 by ysharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str1)
{
	size_t	len;
	int		i;
	char	*str2;

	i = 0;
	len = 0;
	while (str1[len] != '\0')
		len++;
	str2 = (char *)malloc(sizeof(char) * len + 1);
	if (str2 == NULL)
		return (NULL);
	while (str1[i] != '\0')
	{
		str2[i] = str1[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

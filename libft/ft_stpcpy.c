#include "libft.h"

char	*ft_stpcpy(char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] = s2[i]))
		++i;
	return (s1 + i);
}

#include "lem_in.h"

int arr_size(char **arr)
{
	int	size;

	size = 0;
	while (arr[size])
		++size;
	return (size);
}

void free_everything(t_map *map)
{
	int i;

	i = 0;
	while (i < map->num_rooms)
	{
		free(map->rooms[i]->links);
		free(map->rooms[i++]);
	}
	free(map->rooms);
}

int set_num(char *str, int *value)
{
	long n;
	int sign;

	if (!*str)
		return (0);
	sign = (*str == '-') ? -1 : 1;
	if (sign == -1)
		++str;
	n = 0;
	while (*str)
	{
		if ((int)(*str - '0') > 9)
			return (0);
		n = (n * 10) + ((*str++ - '0') * sign);
		if (n > 2147483647 || n < -2147483648)
			return (0);
	}
	*value = (int)n;
	return (1);
}

void error()
{
	write(1, "ERROR\n", 6);
	exit(1);
}
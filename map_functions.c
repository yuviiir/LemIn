#include "lem_in.h"

t_room *add_rooms(t_map *map, char *line)
{
	t_room *room;
	char **arr;

	if (line[0] == ' ')
		error();
	arr = ft_strsplit(line, ' ');
	if (arr_size(arr) != 3)
		error();
	room = add_room(map, arr);
	if (!room)
		free(line);
	return (room);
}

int	add_links(t_map *map, char *line)
{
	int res;
	char **temp;

	res = 0;
	temp = ft_strsplit(line, '-');
	if (arr_size(temp) != 2)
		error();
	res = link_rooms(map, temp);
	free(line);
	return (res);
}


int	add_command(t_map *map, char *command)
{
	t_room **value;
	t_room *room;
	char *line;

	value = NULL;
	if (!ft_strcmp(command, "##start"))
		value = &map->start;
	else if (!ft_strcmp(command, "##end"))
		value = &map->end;
	else
		return (1);
	if (get_next_line(0, &line) < 1)
	{
		free(command);
		return (0);
	}
	room = add_rooms(map, line);
	if (room)
		*value = room;
	free(command);
	return (room ? 1 : 0);
}

void read_map(t_map *map)
{
	char *line;
	int res;

	res = 1;
	line = NULL;
	map->ants = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (map->ants == 0)
			set_num(line, &map->ants);
		else if (*line == '#')
			res = add_command(map, line);
		else
		{
			if (ft_strchr(line, '-'))
				res = add_links(map, line);
			else
				res = (add_rooms(map, line) ? 1 : 0);
		}
		if (!res)
			break ;
	}
	free(line);
}
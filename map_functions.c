#include "lem_in.h"

t_room *add_rooms(t_map *map, char *line)
{
	t_room *room;
	char **arr;

	if (line[0] == ' ')
	{
		free_everything(map);
		free(line);
		error();
	}
	arr = ft_strsplit(line, ' ');
	if (arr_size(arr) != 3)
	{
		free_everything(map);
		free(line);
		free(arr);
		error();
	}
	room = add_room(map, arr);
	if (!room)
		free(line);
	free(arr);
	return (room);
}

int	add_links(t_map *map, char *line)
{
	int res;
	char **temp;

	res = 0;
	temp = ft_strsplit(line, '-');
	if (arr_size(temp) != 2)
	{
		free_everything(map);
		free(line);
		free(temp);
		error();
	}
	res = link_rooms(map, temp);
	free(line);
	free(temp);
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
	while (*line == '#')
	{
		get_next_line(0, &line);
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
	int complete_rooms;

	res = 1;
	complete_rooms = 0;
	line = NULL;
	map->ants = 0;
	map->num_rooms = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (map->ants == 0 && set_num(line, &map->ants))
		{
			set_num(line, &map->ants);
			free(line);
		}
		else if (*line == '#' && map->ants)
			res = add_command(map, line);
		else
		{
			if (ft_strchr(line, '-'))
			{
				if (!map->start || !map->rooms)
				{
					free_everything(map);
					free(line);
				}
				res = add_links(map, line);
				complete_rooms = 1;
			}
			else
			{
				if (complete_rooms == 1)
				{
					free_everything(map);
					free(line);
					error();
				}
				res = (add_rooms(map, line) ? 1 : 0);
			}
		}
		if (!res)
			break ;
	}
	free(line);
}
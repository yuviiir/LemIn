#include "lem_in.h"

t_room *make_room(char **arr)
{
	t_room *room;

	if (!(room = ft_memalloc(sizeof(t_room))))
	{
		free(arr);
		error();
	}
	room->name = arr[0];
	if (!set_num(arr[1], &room->pos_x) || !set_num(arr[2], &room->pos_y))
	{
		free(arr);
		free(room);
		error();
	}
	return (room);
}

t_room *check_room(t_room **rooms, int size, char *name)
{
	t_room *room;
	int i;

	i = 0;
	while (i < size)
	{
		room = rooms[i++];
		if (!ft_strcmp(name, room->name))
			return (room);
	}
	return (NULL);
}

t_room *add_room(t_map *map, char **arr)
{
	t_room **tmp;
	t_room *room;

	room = make_room(arr);
	if (arr_size(arr) != 3 || !*arr[0] || *arr[0] == 'L'
		|| check_room(map->rooms, map->num_rooms, arr[0]) || !room)
	{
		free_everything(map);
		free(room);
		free(arr);
		error();
	}
	tmp = map->rooms;
	if (!(map->rooms = ft_memalloc(sizeof(t_room) * (map->num_rooms + 1))))
	{
		free_everything(map);
		free(room);
		free(arr);
		free(tmp);
		error();
	}
	ft_memcpy(map->rooms, tmp, sizeof(t_room) * map->num_rooms);
	room->room_id = map->num_rooms;
	map->rooms[map->num_rooms++] = room;
	free(tmp);
	return (room);
}

void add_link(t_room *dst, t_room *to_add)
{
	t_room **tmp;

	if (!ft_strcmp(dst->name, to_add->name)
		|| check_room(dst->links, dst->num_links, to_add->name))
		return ;
	tmp = dst->links;
	if (!(dst->links = ft_memalloc(sizeof(t_room) * (dst->num_links + 1))))
	{
		free(tmp);
		free(dst);
		free(to_add);
		error();
	}
	ft_memcpy(dst->links, tmp, sizeof(t_room) * dst->num_links);
	dst->links[dst->num_links++] = to_add;
	free(tmp);
}

int link_rooms(t_map *map, char **arr)
{
	t_room *a;
	t_room *b;

	a = check_room(map->rooms, map->num_rooms, arr[0]);
	b = check_room(map->rooms, map->num_rooms, arr[1]);
	if (arr_size(arr) != 2 || !a || !b)
	{
		free_everything(map);
		free(a);
		free(b);
		free(arr);
		error();
	}
	add_link(a, b);
	add_link(b, a);
	return (1);
}
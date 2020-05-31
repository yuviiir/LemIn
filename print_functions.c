#include "lem_in.h"

void print_links(t_map *map)
{
	t_room *room;
	t_room *link;
	int i;
	int j;

	i = 0;
	while (i < map->num_rooms)
	{
		room = map->rooms[i++];
		j = 0;
		while (j < room->num_links)
		{
			link = room->links[j++];
			if (link->room_id > room->room_id)
			{
				write(1, room->name, ft_strlen(room->name));
				write(1, "-", 1);
				write(1, link->name, ft_strlen(link->name));
				write(1, "\n", 1);
			}
		}
	}
}

void print_rooms(t_map *map)
{
	t_room *room;
	int i;

	i = 0;
	while (i < map->num_rooms)
	{
		room = map->rooms[i++];
		if (room == map->start)
		{
			write(1, "##start", 7);
			write(1, "\n", 1);
		}
		if (room == map->end)
		{
			write(1, "##end", 5);
			write(1, "\n", 1);
		}
		write(1, room->name, ft_strlen(room->name));
		write(1, " ", 1);
		ft_putnbr(room->pos_x);
		write(1, " ", 1);
		ft_putnbr(room->pos_y);
		write(1, "\n", 1);
	}
}

void print_map(t_map *map)
{
	ft_putnbr(map->ants);
	write(1, "\n", 1);
	print_rooms(map);
	print_links(map);
}
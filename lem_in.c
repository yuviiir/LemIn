#include "lem_in.h"

int	find_shortest_path(t_queue *queue, t_room *end)
{
	t_room	*room;
	t_room	*link;
	int		i;

	while (queue->start)
	{
		if ((room = remove_from_queue(queue)) == end)
			break ;
		i = 0;
		while (i < room->num_links)
		{
			link = room->links[i++];
			if (!link->parent_room)
			{
				link->parent_room = room;
				add_to_queue(queue, link);
			}
		}
	}
	while (queue->start)
		remove_from_queue(queue);
	return (room == end);
}

void		paths(t_room *start, t_room *end)
{
	end->links[0] = NULL;
	while (end)
	{
		end->parent_room->links[0] = end;
		end = (end->parent_room != start) ? end->parent_room : NULL;
	}
}

void		move_ants(t_queue *queue)
{
	t_ant	*ant;
	void 	*tmp;
	t_node	*node;
	t_node	*next;

	node = queue->start;
	while (node)
	{
		ant = node->data;
		ant->room = ant->room->links[0];
		write(1, "L", 1);
		ft_putnbr(ant->id);
		write(1, "-", 1);
		write(1, ant->room->name, ft_strlen(ant->room->name));
		next = node->next;
		if (!ant->room->links[0])
		{
			tmp = remove_from_queue(queue);
			free(tmp);
		}
		if ((node = next))
			write(1, " ", 1);
	}
	write(1, "\n", 1);
}

void		move(t_map *map)
{
	t_ant	*ant;
	t_queue	*queue;
	int		i;

	i = 1;
	queue = (t_queue *)ft_memalloc(sizeof(t_queue));
	while (i <= map->ants || queue->start)
	{
		if (i <= map->ants)
		{
			ant = ft_memalloc(sizeof(t_ant));
			ant->id = i++;
			ant->room = map->start;
			add_to_queue(queue, ant);
		}
		if (queue->start)
			move_ants(queue);
	}
	free(queue);
	free(ant);
}

void			lem_in(t_map *map)
{
	t_queue	*queue;

	queue = (t_queue *)ft_memalloc(sizeof(t_queue));
	map->start->parent_room = map->start;
	add_to_queue(queue, map->start);
	if (!find_shortest_path(queue, map->end))
	{
		free_everything(map);
		free(queue);
		error();
	}
	print_map(map);
	ft_putchar('\n');
	paths(map->start, map->end);
	move(map);
	free(queue);
}
#include "lem_in.h"

void	*remove_from_queue(t_queue *queue)
{
	void	*data;
	t_node	*next;

	if (!queue->start)
		return (NULL);
	data = queue->start->data;
	if (queue->start == queue->end)
		queue->end = NULL;
	next = queue->start->next;
	free(queue->start);
	queue->start = next;
	return (data);
}

int	add_to_queue(t_queue *queue, void *data)
{
	t_node	*new;

	if (!(new = (t_node *)ft_memalloc(sizeof(t_node))))
		return (0);
	new->data = data;
	if (!queue->start)
		queue->start = new;
	if (queue->end)
		queue->end->next = new;
	queue->end = new;
	return (1);
}

int main(void)
{
	t_map map;

	ft_memset(&map, 0, sizeof(t_map));
	read_map(&map);
	if (map.ants < 1 || map.num_rooms < 1 || !map.start || !map.end)
	{
		free_everything(&map);
		error();
	}
	if (map.start == map.end)
	{
		print_map(&map);
		free_everything(&map);
		return (0);
	}
	lem_in(&map);
	free_everything(&map);
	return (0);
}
#ifndef LEMIN_H
# define LEMIN_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_room
{
	char			*name;
	int				room_id;
	int				num_links;
	struct s_room	**links;
	int				pos_x;
	int				pos_y;
	struct s_room	*parent_room;
}				t_room;

typedef struct	s_map
{
	int				ants;
	int				num_rooms;
	t_room			*start;
	t_room			*end;
	t_room			**rooms;
}				t_map;

typedef struct	s_path
{
	int			num;
	int			*length;
	char		***name;
}				t_path;

typedef struct	s_ant
{
	int				id;
	t_room			*room;
}				t_ant;

typedef struct	s_node
{
	void			*data;
	struct s_node	*next;
}				t_node;

typedef struct	s_queue
{
	t_node	*start;
	t_node	*end;
}				t_queue;

void        read_map(t_map *map);

void	    error();

char		**split(char *raw, char delim);

void	    print_map(t_map *map);

void		move(t_map *map);

t_room	    *add_room(t_map *map, char **params);

int		    link_rooms(t_map *map, char **params);

int		    arr_size(char **arr);

void		free_everything(t_map *map);

int 		set_num(char *str, int *coord);

void		lem_in(t_map *map);

int			add_to_queue(t_queue *queue, void *data);

void		*remove_from_queue(t_queue *queue);

int			print_results(t_path path, int ants);

#endif
#include "libft.h"

static t_file	*get_buffer(t_file **head, int fd, int destroy)
{
	t_file	*next;

	while (*head && (*head)->fd != fd)
		head = &(*head)->next;
	if (!*head)
	{
		*head = (t_file *)ft_memalloc(sizeof(t_file));
		if (!*head)
			return (NULL);
		if (!((*head)->buffer = ft_memalloc(BUFF_SIZE + 1)))
		{
			ft_memdel((void **)head);
			return (NULL);
		}
		(*head)->fd = fd;
	}
	if (destroy)
	{
		next = (*head)->next;
		free((*head)->buffer);
		free(*head);
		*head = next;
	}
	return (*head);
}

static int	append(char **line, char *buffer, int n)
{
	char	*tmp;
	int	len;

	if (!*line)
	{
		if (!(*line = ft_strsub(buffer, 0, n)))
			return (0);
	}
	else
	{
		tmp = *line;
		len = ft_strlen(tmp) + n;
		if (!(*line = (char *)malloc(len + 1)))
			return (0);
		ft_memcpy(ft_stpcpy(*line, tmp), buffer, n);
		(*line)[len] = '\0';
		free(tmp);
	}
	return (1);
}

static int		build_line(t_file **head, char **line, t_file *file)
{
	char	*buffer;
	int	n;

	if (!*(buffer = file->buffer + file->offset))
		return (0);
	n = 0;
	while (buffer[n] && buffer[n] != '\n')
		++n;
	if (!append(line, buffer, n))
	{
		get_buffer(head, file->fd, 1);
		if (*line)
			ft_memdel((void **)line);
		return (-1);
	}
	if (buffer[n] == '\n')
	{
		file->offset += n + 1;
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*head;
	t_file			*file;
	int			bytes;
	int				nl;

	if (!line || !(file = get_buffer(&head, fd, 0)))
		return (-1);
	*line = NULL;
	while (!(nl = build_line(&head, line, file)))
	{
		if ((bytes = read(fd, file->buffer, BUFF_SIZE)) < 1)
		{
			get_buffer(&head, fd, 1);
			if (*line && bytes < 0)
				ft_memdel((void **)line);
			return ((*line) ? 1 : bytes);
		}
		file->buffer[bytes] = '\0';
		file->offset = 0;
	}
	return (nl);
}
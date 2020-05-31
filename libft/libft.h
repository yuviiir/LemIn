#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 4096

typedef struct	s_file
{
	int				fd;
	int			offset;
	char			*buffer;
	struct s_file	*next;
}				t_file;

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	*ft_memcpy(void *dst, const void *src, size_t n);

void	*ft_memmove(void *dst, const void *src, size_t len);

void	*ft_memset(void *b, int c, size_t len);

char	*ft_strchr(const char *s, int c);

int		ft_strcmp(const char *s1, const char *s2);

char	*ft_strcpy(char *dst, const char *src);

size_t	ft_strlen(const char *str);

void	*ft_memalloc(size_t size);

void	ft_memdel(void **ap);

char	*ft_strdup(const char *str1);

size_t	ft_strlen(const char *str);

void	ft_putchar(char c);

void	ft_putendl(char const *s);

void	ft_putnbr(int n);

void	ft_putstr(const char *s);

char	*ft_stpcpy(char *s1, const char *s2);

char	*ft_strsub(char const *s, unsigned int start, size_t len);

char		**ft_strsplit(char *raw, char delim);

int		get_next_line(const int fd, char **line);

char	*ft_strncpy(char *dest, const char *src, size_t len);

#endif

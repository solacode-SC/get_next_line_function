#include "get_next_line_bonus.h"

static int	new_line_in(char *b)
{
	while (*b)
	{
		if (*b == '\n')
			return (1);
		b++;
	}
	return (0);
}

int	no_new_line_in(char *b)
{
	if (new_line_in(b))
		return (0);
	return (1);
}

// In the two functions above, b stands for BUFFER, for convenience.

static char	*current_buffer(int fd, char *cb, int *vr)
{
	*vr = read(fd, cb, BUFFER_SIZE);
	if (*vr < 0)
	{
		free(cb);
		return (NULL);
	}
	cb[*vr] = '\0';
	return (cb);
}

// READ_BS above stands for: Read the Current Buffer

static char	*joinline(int fd, char **line, int *vr)
{
	char	*cb;
	char	*tail;

	tail = NULL;
	cb = malloc(BUFFER_SIZE + 1);
	if (!cb)
		return (NULL);
	cb = current_buffer(fd, cb, vr);
	*line = ft_strjoin(*line, cb, 1, 0);
	while (*vr > 0 && no_new_line_in(cb))
	{
		cb = current_buffer(fd, cb, vr);
		*line = ft_strjoin(*line, cb, 1, 0);
	}
	if (new_line_in(*line))
	{
		tail = after_nl(*line);
		*line = ft_strjoin(NULL, until_nl(*line), 0, 1);
	}
	free(cb);
	return (tail);
}

char	*get_next_line(int fd)
{
	static char	*tail[OPEN_MAX];
	int			vr;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = ft_strjoin("", "", 0, 0);
	if (tail[fd])
	{
		line = ft_strjoin(tail[fd], line, 0, 1);
		if (tail[fd])
			free(tail[fd]);
		tail[fd] = NULL;
	}
	tail[fd] = joinline(fd, &line, &vr);
	if (line[0] == '\0' || vr < 0)
		return (free(line), free(tail[fd]), tail[fd] = NULL, NULL);
	return (line);
}

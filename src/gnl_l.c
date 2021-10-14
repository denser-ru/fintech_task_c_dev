#include "simulator.h"

static size_t	get_line(char *line, char *buf, size_t len);

int				gnl_l(int fd, char *line)
{
	static char		buf[FT_LINE_BUF + 1];
	static char		*p = buf;
	size_t			len;

	len = 0;
	if (p == buf)
		len = read(fd, p, FT_LINE_BUF);
	len =  get_line(line, p, FT_LINE_BUF);
	p += len;
	if (*p != '\n')
	{
		p = buf;
		read(fd, buf, FT_LINE_BUF);
		p += get_line(line + len, p, FT_LINE_BUF);
		len += p - buf;
	}
	if (*p != '\n')
		return (-1);
	line[len] = '\0';
	*p = '\0';
	return ((int)(p++ - buf));
}

static size_t	get_line(char *line, char *buf, size_t len)
{
	size_t	size;

	size = 0;
	while (size < len && *buf && *buf != '\n')
	{
		*line = *buf;
		++line;
		++buf;
		++size;
	}
	return (size);
}
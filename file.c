#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);

static const int	BSIZE = 10;
static const char	*FILE_PATH = "numbers.dict";

int	get_file_size()
{
	int fd;
	int	bytes;
	int file_size;
	char *buf;

	bytes = 0;
	file_size = 0;
	buf = (char *)malloc(BSIZE * sizeof(char));
	fd = open(FILE_PATH, O_RDONLY);
	if (buf == NULL || fd == -1)
		return -1;
	while ((bytes = read(fd, buf, BSIZE)) > 0)
        	file_size += bytes;
	free(buf);
	close(fd);
	return (file_size);
}

int	get_file_lines_qt()
{
	int	i;
	char	*buf;
	int	count;
	int	file_size;

	i = 0;
	count = 0;
	file_size = get_file_size();
	buf = (char *)malloc(BSIZE * sizeof(char));
	if (buf == NULL || file_size < 0)
		return -1;
	while (i < file_size)
	{
		if(buf[i] == '\n')
			count++;
		i++;
	}
	count++;
	free(buf);
	return count;
}

int	get_line_width()
{
	int i;
	int size;
	int temp;
	char *buf;
	
	i = 0;
	size = 0;
	buf = (char *)malloc(BSIZE * sizeof(char));
	if (buf == NULL || get_file_size() < 0)
		return -1;
	while (i < get_file_size())
	{
		temp = 0;
		while(buf[i] != '\n')
		{
			temp++;
			i++;
		}
		if (temp > size)
			size = temp;
		i++;
	}
	free(buf);
	return size;
}

void	read_file()
{
	int fd;
	int bytes;
	char *buf;

	bytes = 0;
	buf = (char *)malloc(get_file_size() * sizeof(char));
	fd = open(FILE_PATH, O_RDONLY);
	if (buf == NULL || fd == -1)
		ft_putstr("Dict Error\n");
	bytes = read(fd, buf, get_file_size());
	buf[bytes] = '\0';
	ft_putstr(buf);
	free(buf);
	close(fd);
}

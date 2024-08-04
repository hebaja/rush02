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
	while ((bytes = read(fd, buf, BSIZE)) > 0) {
        file_size += bytes;
    }
	/*
	ft_putnbr(file_size);
	ft_putchar('\n');
	*/
	free(buf);
	close(fd);
	return (file_size);
}

int get_file_lines_qt()
{
	int i;
	int fd;
	char *buf;
	int count;

	i = 0;
	count = 0;
	buf = (char *)malloc(BSIZE * sizeof(char));
	fd = open(FILE_PATH, O_RDONLY);
	while (i < get_file_size())
	{
		if(buf[i] == '\n')
			count++;
		i++;
	}
	count++;
	free(buf);
	close(fd);
	return count;
}

int		get_line_width()
{
	int i;
	int fd;
	int size;
	int temp;
	char *buf;
	
	i = 0;
	size = 0;
	buf = (char *)malloc(BSIZE * sizeof(char));
	fd = open(FILE_PATH, O_RDONLY);
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
	close(fd);
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
	bytes = read(fd, buf, get_file_size());
	buf[bytes] = '\0';
	ft_putnbr(get_file_lines_qt());
	ft_putchar('\n');
	ft_putnbr(get_line_width());
	ft_putchar('\n');
	ft_putstr(buf);
	ft_putchar('\n');
	free(buf);
	close(fd);
}

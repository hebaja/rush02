#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);

static const int	BSIZE = 10;
static const char	*FILE_PATH = "numbers.dict";

int	get_file_size(int fd, char *buf)
{
	int	bytes;
	int file_size;

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
	close(fd);
	return (file_size);
}

int get_file_lines_qt(char *buf, int file_size)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < file_size)
	{
		if(buf[i] == '\n')
			count++;
		i++;
	}
	return count;
}

int		get_line_width(char *buf, int file_size)
{
	int i;
	int size;
	int temp;
	
	i = 0;
	size = 0;
	while (i < file_size)
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
	return size;
}

void	read_file(int fd, char *buf, int file_size)
{
	int bytes;

	bytes = 0;
	buf = (char *)malloc(file_size * sizeof(char));
	fd = open(FILE_PATH, O_RDONLY);
	bytes = read(fd, buf, file_size);
	buf[bytes] = '\0';
	ft_putnbr(get_file_lines_qt(buf, file_size));
	ft_putchar('\n');
	ft_putnbr(get_line_width(buf, file_size));
	ft_putchar('\n');
	ft_putstr(buf);
	ft_putchar('\n');
	free(buf);
	close(fd);
}


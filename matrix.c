#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	ft_putchar(char c);
int		get_line_width(char *buf, int file_size);
int		get_file_lines_qt(char *buf, int file_size);

static const char	*FILE_PATH = "numbers.dict";

void	print_matrix(char **matrix, int lines)
{
	int		x;
	int		y;

	x = 0;
	while (x < lines)
	{
		y = 0;
		while (matrix[x][y] != '\0')
		{
			ft_putchar(matrix[x][y]);
			y++;
		}
		ft_putchar('\n');
		x++;
	}
}

void	populate_matrix(char *buf, char **matrix, int file_size)
{
	int		buf_i;
	int		x;
	int		y;
	int		lines;

	buf_i = 0;
	lines = get_file_lines_qt(buf, file_size);
	x = 0;
	while (x < lines)
	{
		y = 0;
		while (buf[buf_i] != '\n')
		{
			matrix[x][y] = buf[buf_i];
			y++;
			buf_i++;
		}
		matrix[x][y] = '\0';
		buf_i++;
		x++;
	}
	print_matrix(matrix, lines);
}

void	create_matrix(int fd, char *buf, char **matrix, int file_size)
{
	int i;
	int bytes;
	int rows;
	int cols;

	i = 0;
	buf = (char *)malloc(file_size * sizeof(char));
	fd = open(FILE_PATH, O_RDONLY);
	bytes = read(fd, buf, file_size);
	buf[bytes] = '\0';
	rows = get_file_lines_qt(buf, file_size);
	cols = get_line_width(buf, file_size);
	matrix = (char **)malloc(rows * sizeof(char *));
	while (i < rows)
	{
        matrix[i] = (char *)malloc(cols * sizeof(char));
		i++;
	}
	populate_matrix(buf, matrix, file_size);
}


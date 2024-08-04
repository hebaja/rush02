#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		get_file_size();
int		get_line_width();
int		get_file_lines_qt();

static const char	*FILE_PATH = "numbers.dict";

void	free_m(char **matrix)
{
	int i;
	int rows;

	i = 0;
	rows = get_file_lines_qt();
	while (i < rows)
	{
		free(matrix[i]);
		i++;
	}
	free (matrix);
}

void	print_matrix(char **matrix)
{
	int		x;
	int		y;
	int		lines;

	x = 0;
	lines = get_file_lines_qt();
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
	free_m(matrix);

}

char	**populate_matrix(char *buf, char **matrix)
{
	int		x;
	int		y;
	int		buf_i;
	int		lines;

	buf_i = 0;
	lines = get_file_lines_qt();
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
	return matrix;
}

char	**create_matrix(int fd, char *buf)
{
	int i;
	int bytes;
	int rows;
	int cols;
	char **matrix;

	i = 0;
	buf = (char *)malloc(get_file_size() * sizeof(char));
	fd = open(FILE_PATH, O_RDONLY);
	bytes = read(fd, buf, get_file_size());
	buf[bytes] = '\0';
	rows = get_file_lines_qt();
	cols = get_line_width();
	matrix = (char **)malloc(rows * sizeof(char *));
	while (i < rows)
	{
        matrix[i] = (char *)malloc(cols * sizeof(char));
		i++;
	}
	close(fd);
	return (populate_matrix(buf, matrix));
}


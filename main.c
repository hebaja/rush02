#include <stdlib.h>

int	get_file_size();
int	get_file_lines_qt();
void	read_file();
char	**create_matrix(int fd, char *buf);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	print_matrix(char **matrix);
void	ft_putstr(char *str);
void	ft_putchar(char c);

int	main()
{
	int	fd_matrix;
	char	*buf_matrix;
	char	**matrix;

	read_file();
	ft_putchar('\n');

	matrix = create_matrix(fd_matrix, buf_matrix);
	if (matrix != NULL)
	{
		//print_matrix(matrix[]);
		ft_putstr(matrix[3]);
		//ft_putchar('\n');
	}
	else
		ft_putstr("Dict Error\n");
	return (0);
}

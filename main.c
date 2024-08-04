int		get_file_size();
int		get_file_lines_qt();
void	read_file(int fd, char *buf, int file_size);
char 	**create_matrix(int fd, char *buf);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
void    print_matrix(char **matrix);

int	main()
{
	int		fd_matrix;
	int		file_size;
	int		rows;
	char	*buf_matrix;
	char	**matrix;

	//read_file(fd_read, buf_read, file_size);
	matrix = create_matrix(fd_matrix, buf_matrix);
	print_matrix(matrix);
	return (0);
}

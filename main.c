int		get_file_size(int fd, char *buf);
void	read_file(int fd, char *buf, int file_size);
void	create_matrix(int fd, char *buf, char **matrix, int file_size);

int	main()
{
	int	fd_count;
	int	fd_read;
	int fd_matrix;
	int file_size;
	char	*buf_count;
	char	*buf_read;
	char	*buf_matrix;
	char	**matrix;

	file_size = get_file_size(fd_count, buf_count);
	//read_file(fd_read, buf_read, file_size);
	create_matrix(fd_matrix, buf_matrix, matrix, file_size);
	return (0);
}

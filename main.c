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
int	ft_strlen(char *str);

void	find_nbr(char **matrix)
{
	int	i;
	char	*n;

	i = 0;
	while(matrix[4][i] != '\0')
	{
		if(matrix[4][i] == 32)
		{
			n = &matrix[4][i + 1];
			break ;
		}
		i++;
	}
	ft_putstr(n);
}

void	printit(int is_space, int nb, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{	
		if (str[i] >= 'a' && str[i] <= 'z')
			ft_putchar(str[i]);
		i++;
	}
	if (is_space)
		ft_putchar(' ');
}

void	one_to_hundred(int nb, char **matrix)
{
	if (nb >= 1 && nb <= 20)
	{
		printit(0, nb, matrix[nb]);
		return ;
	}
	else if (nb >= 20 && nb <= 29)
	{
		printit(1, nb, matrix[20]);
		one_to_hundred(nb % 20, matrix);
	}
	else if (nb >= 30 && nb <= 39)
	{
		printit(1, nb, matrix[21]);
		one_to_hundred(nb % 30, matrix);
	}
	else if (nb >= 40 && nb <= 49)
	{
		printit(1, nb, matrix[22]);
		one_to_hundred(nb % 40, matrix);
	}
	else if (nb >= 50 && nb <= 59)
	{
		printit(1, nb, matrix[23]);
		one_to_hundred(nb % 50, matrix);
	}
	else if (nb >= 60 && nb <= 69)
	{
		printit(1, nb, matrix[24]);
		one_to_hundred(nb % 60, matrix);
	}
	else if (nb >= 70 && nb <= 79)
	{
		printit(1, nb, matrix[25]);
		one_to_hundred(nb % 70, matrix);
	}
	else if (nb >= 80 && nb <= 89)
	{
		printit(1, nb, matrix[26]);
		one_to_hundred(nb % 80, matrix);
	}
	else if (nb >= 90 && nb <= 99)
	{
		printit(1, nb, matrix[27]);
		one_to_hundred(nb % 90, matrix);
	}
}

int	get_first_digit(int nb)
{
	while (nb >= 10)
		nb /= 10;
	return (nb);
}

void	hundred_to_thousand(int nb, char **matrix)
{
	if (nb >= 100)
	{
		printit(1, nb, matrix[get_first_digit(nb)]);
		printit(1, nb, matrix[28]);
		one_to_hundred(nb % 100, matrix);
	}
}

int	main(int argc, char **argv)
{
	int	fd_matrix;
	char	*buf_matrix;
	char	**matrix;

	int nb = atoi(argv[1]);

	matrix = create_matrix(fd_matrix, buf_matrix);
	if (nb == 0)
		ft_putstr("zero");
	else if (nb <= 99)
		one_to_hundred(nb, matrix);
	else if (nb >= 100 && nb <= 999)
		hundred_to_thousand(nb, matrix);

	
	/*
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

	find_nbr(matrix);
	*/

	return (0);
}

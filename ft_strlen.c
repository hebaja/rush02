int	ft_strlen(char *str)
{
	int size_arr = 0;
	while (str[size_arr] != 0)
		size_arr++;
	return (size_arr);
}

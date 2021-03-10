//voir ex00
int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (i < length)
	{
		if ((*f)(tab[i]))
			count++;
		i++;
	}
	return (count);
}

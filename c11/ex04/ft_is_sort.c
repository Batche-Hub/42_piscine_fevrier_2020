// voir ex00
int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int asc;
	int desc;

	i = 0;
	asc = 0;
	desc = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			asc = 1;
		else if (f(tab[i], tab[i + 1]) > 0)
			desc = 1;
		if (desc != 0 && asc != 0 && desc == asc)
			return (0);
		i++;
	}
	return (1);
}

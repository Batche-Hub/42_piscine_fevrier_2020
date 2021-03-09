// Une des façon d'inversion un tableau, ici un tableau d'entiers de type int
// Il y a de nombreuses manière de faire cela.
// Par ex avec les opérateur bitwise.
// duckduckgo ==> bitwise operator

void	ft_rev_int_tab(int *tab, int size)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = size - 1;
	while (i < size / 2)
	{
		temp = tab[j];
		tab[j] = tab[i];
		tab[i] = temp;
		i++;
		j--;
	}
}

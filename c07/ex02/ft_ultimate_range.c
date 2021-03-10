// **range est un pointeur sur un pointeur sur int. Pas une double tableau.
// Pour tester, on récupère l'adresse du pointeur avec &.
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int *tab;
	int i;
	int mem;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	else
		mem = max - min;
	if (!(tab = (int *)malloc(sizeof(int) * (max - min))))
	{
		*range = NULL;
		return (-1);
	}
	i = 0;
	while (min < max)
	{
		tab[i] = min;
		i++;
		min++;
	}
	*range = tab;
	return (mem);
}

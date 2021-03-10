//voir ex00
#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int *res;
	int i;

	i = -1;
	if (!(res = (int *)malloc(sizeof(int) * length)))
		return (NULL);
	while (++i < length)
		res[i] = (*f)(tab[i]);
	return (res);
}

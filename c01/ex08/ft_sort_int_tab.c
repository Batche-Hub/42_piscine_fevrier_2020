// Méthode divide and conqueer
// En gros, on sépare notre tableau selon un pivot (au départ) arbitrairement choisi (ici c'est le dernier élément du tableau)
// Puis on trie en fonction de ce pivot.
// Et on réorganise le tableau en fonction de ce qu'on avant et après le pivot, qu'on recalcule ensuite, de
//telle sorte à se rapprocher de plus en plus du pivot et que les index soit égaux (iuls changent en fonction du pivot) et donc le tableau trié.
// c'est une méthode compliquée mais plus rapide que le tri à bulle etc.
// Si vous commencez le code, je vous invite à plutôt voir les autres type de tri, plus accessibles (comme le tri à bulle).
void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		ft_part(int arr[], int min_index, int max_index)
{
	int pivot;
	int i;
	int j;

	pivot = arr[max_index];
	i = min_index - 1;
	j = min_index;
	while (j <= max_index - 1)
	{
		if (arr[j] <= pivot)
		{
			i++;
			ft_swap(&arr[i], &arr[j]);
		}
		j++;
	}
	ft_swap(&arr[i + 1], &arr[max_index]);
	return (i + 1);
}

void	ft_sort(int tab[], int min_index, int max_index)
{
	int pivot;

	if (min_index < max_index)
	{
		pivot = ft_part(tab, min_index, max_index);
		ft_sort(tab, min_index, pivot - 1);
		ft_sort(tab, pivot + 1, max_index);
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	ft_sort(tab, 0, size - 1);
}

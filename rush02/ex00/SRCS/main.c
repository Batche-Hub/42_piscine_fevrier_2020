// ne surtout pas reproduire les codes de ce rush, c'est mauvais !
#include "ft.h"

int main(void)
{
	char **numbers;
	char **letters;
	char *dict1;
	int i;

	i = 0;
	dict1 = make_arr_char("numbers.dict");
	if (dict1 != NULL)
	{
		numbers = ft_split_numbers(dict1);
		letters = ft_split_letters(dict1);
	}
	else
		return (error());
	while (numbers[i])
	{
		ft_putstr(numbers[i]);
		write(1, " => ", 4);
		ft_putstr(letters[i]);
		write(1, "\n", 1);
		i++;
	}
	free(dict1);
	return (0);
}

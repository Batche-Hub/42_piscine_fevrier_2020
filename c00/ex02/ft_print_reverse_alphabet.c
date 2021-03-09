#include <unistd.h>
//se référer à l'ex01

void	ft_print_reverse_alphabet(void)
{
	char c;

	c = '{';
	while (--c >= 'a')
		write(1, &c, 1);
}

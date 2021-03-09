#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
// On retrouve putnbr mais en encore plus sophistiqué. ici, on sait qu'il y aura des nombres plus grand que 10, donc si on veut avoir toutes les unités, dizaines centaines..
// Il faut nécessairement "récupérer" ces dizaines centaines etc.. Vu qu'on est en base 10, on divise par 10. En base 2, on diviserait par deux (et on regarderai le reste d'une division par 2).
void	ft_putnbr(int nb)
{
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + 48);
}
// Avec ce qu'on appris avant, l'algo est nouvelle fois relativement simple et très similaire à l'exercice précédent.
void	ft_print_comb2(void)
{
	int i;
	int j;

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			if (i < 10)
				ft_putchar('0');
			ft_putnbr(i);
			ft_putchar(' ');
			if (j < 10)
				ft_putchar('0');
			ft_putnbr(j);
			if (i != 98)
				write(1, ", ", 2);
			j++;
		}
		i++;
	}
}

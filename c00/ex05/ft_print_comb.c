#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
// cett fonction, qu'on verra de façon plus sophistiquée plus tard, sert à "traduire" un entier de type int dans sa représentation dans la table ascii
// == Lumière ==
// N'importe quel entier en base 10 % 10 aura pour reste son unité.
// == Question ==
// Quelle est, en base 10, la représention du chiffre 0 ?
void	ft_putnbr(int nb)
{
	ft_putchar(nb % 10 + 48);
}
// Un algo assez simple.
// Lire correctement l'exemple est fort utile.
// Plus tard on retrouvera (dans le dernier exo), cette combinaison.
void	ft_print_comb(void)
{
	int i;
	int j;
	int k;

	i = 0;
	while (i <= 7)
	{
		j = i + 1;
		while (j <= 8)
		{
			k = j + 1;
			while (k <= 9)
			{
				ft_putnbr(i);
				ft_putnbr(j);
				ft_putnbr(k);
				if (i != 7)
					write(1, ", ", 2);
				k++;
			}
			j++;
		}
		i++;
	}
}

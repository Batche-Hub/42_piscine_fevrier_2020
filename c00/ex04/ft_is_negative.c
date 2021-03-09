#include <unistd.h>
// Ici on doit définir si un nombre est positif ou négatif
// Spoil : 0 est positif ;)
// On peut réutiliser ce qu'on a appris dans les exercices précédents en définissant
// deux variables : une pour le négatif et l'autre pour le positif
// Ensuite on teste : si l'entier n est plus que 0, j'imprime mon char qui représente 'N'
// sinon j'imprime celui qui représente 'P'
void	ft_is_negative(int n)
{
	char p;
	char m;

	p = 'P';
	m = 'N';
	if (n < 0)
		write(1, &m, 1);
	else
		write(1, &p, 1);
}

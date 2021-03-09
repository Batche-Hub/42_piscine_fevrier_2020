#include <unistd.h>
// comme pour putchar, si ce n'est qu'on imprime différents caractère en incrémentant l'adresse du pointeur sur char
// Il y a de nombreuseus manière de la faire
// Par exemple
// int i = 0;
// while (str[i] != '\0')
//	write(1, &str[i], 1);
//	i++;
// Le '\0' est ce qui clos toute chaine de caractère en C. Ca nous permet donc de savoir tout un tas de choses, par exemple calculer
// sa longueur, la comparer, faire des opérations sur les valeurs contenues dans la chaîne etc..
void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

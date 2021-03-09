#include <unistd.h>
//ici, on utilise la même fonction write que pour putchar.
//On veut imprimer l'alphabet, soit de la lettre... a (en minuscule) à 'z'.
// Il y a plusieurs manière de faire. ici, j'incrémente avant d'exécuter l'instruction, il faut donc
//que je mettre c == au char juste avant 'a'. Si je ne faisais pas cela, 'a' ne serait tout simplement pas
//imprimé
// == Lazy tip ==
// on pourrait écrire : write(1, "abcdefghijklmnopqrstuvwxyz", 26);
// == Pro tip ==
// man ascii
void	ft_print_alphabet(void)
{
	char c;

	c = '`';
	while (++c <= 'z')
		write(1, &c, 1);
}

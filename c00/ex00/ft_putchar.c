#include <unistd.h>
// L'idée est d'imprimer un caractère sur la sortie standard. Pour ce faire, on récupère l'adresse du char , on indique la sortie standard, puis le nombre d'octet imprimés
//(1 en l'occurrence).
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

// Le c06 est normalement une formalité sauf si on n'a pas encore vu
// ce qu'est un argument dans un main.
// On a deux choses : ac, qui est le nombre d'argument et est AU MOINS égal à 1.
// Et av, qui est un tableau à deux dimensions, dans lequel sont contenus tous les arguments.
// ac est toujours au égal à 1 car l'argument qu'on a toujours est tout simplement le nom de notre fichier
// Pour av, les différents argumentseront fournis par l'intermédiaire des argument qu'on mettre avant l'execution
// càd :
// ./a.out mes arguments sont cools
// Avec l'exemple ci-dessus, on aurait en :
// av[0] : a.out
// av[1] : mes
// av[2] : arguments
// av[3] : sont
// av[4] : cools
// Donc ac == 5
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

int		main(int ac, char **av)
{
	if (ac)
		ft_putstr(av[0]);
	return (0);
}

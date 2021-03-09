#include <unistd.h>
// == ATTENTION ==
// Cet exercice est assez compliqué.
// Si vous ne comprenez pas le code, c'est vraiment inutile de le copier et le coller.
// Même si vous le "comprenez" ou pensez le comprendre : en effet, c'est toujours plus gratifiant de le réussir par soi-même
// De plus, ma solution n'est vraiment pas élégante et inutilment complexe.
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
// cette fonction sert à comparer les valeurs ascii de deux chaine de caractère.
// Pourquoi ? Car on remarque que le maximum de chaque combinaisons (de n longueur) est très simple à deviner
// Par exemple, pour le max, n = 9, la combinaison max sera "123456789".
// Vu que j'utilise un tableau "0123456789", je peux facilement retrouver ce qui sera ma dernière combinaison dès lors qu'elle intervient
// Si ma focntion renvoie 1, ça veut dire que je suis tombé sur la combinaison maximum. Dès lors, je peux ne pas mettre de ", "
int		ft_strncmp(char *s1, char *s2, int i)
{
	int j;

	j = 0;
	while (s1[j] && s2[i])
	{
		if (s1[j] != s2[i])
			return (0);
		i++;
		j++;
	}
	return (1);
}
// une affreuse fonction hyper débile
// Je vas tenter de l'expliquer correctement.
// On a en gros un tableau de char, un n (la taille max du tableau), l'index dans lequel on se trouve dans le tableau comb (celui de taille n) ainsi que
// l'index (i) du tableau avec tous les chiffres. Ouf !
void	ft_combine(char comb[], int n, int index, int i)
{
	int		j;
	char	*arr;
//Le tableau de référence avec tous les chiffres dans lequel on va se balader
	arr = "0123456789";
	j = 0;
// Cette condition nous permet d'arrêter le résultat et de l'imprimer.
// En effet, le récursion va tester tous les chiffres jusqu'à arriver à index == n, fourni en paramètre, qui est le maximum
// de taille autorisé. Si mon n == 2 alors dès que mon index est égal à deux (et qu'une combinaison a donc été opérée
// je vais pouvoir imprimer le résultat.
	if (index == n)
	{
		while (j < n)
		{
			ft_putchar(comb[j]);
			j++;
		}
		write(2, ", ", (!(ft_strncmp(comb, arr, 9 - (n - 1))) ? 2 : 0));
		return ;
 	}
	if (i >= 10)
		return ;
// Ici j'infique que à l'index en cours (qui ne sera jamais plus grand que n, cf plus haut), correspond mon index i dans la tableau principal.
	comb[index] = arr[i];
// Ici est la récursion, qui est plus compliqué qu'elle ne mérite. En gros, la récursion sert à "trouver" des valeur toujours différentes
// de celles qu'on a eues précedemment. Cf wikipédia.
//On incrémente l'index de notre tableau et/l'index du tableau de référence. Faire les deux, dans cette implémentation est nécessaire car sinon on se retrouve dans le cas
// où soit notre tableau final est vide, soit il contient seulement la première combinaison.
// Cette partie là est clairement améliorable, voir l'ex08 du c05 pour une meilleure utilisation (et beaucoup plus propre) de la récursion, ou encore le rush01
// dans la partie "solver".
	ft_combine(comb, n, index + 1, i + 1);
	ft_combine(comb, n, index, i + 1);
}
// La fonction principale, diablement petite, ou on initialise la taille du tableau qui contiendra toutes nos combinaisons à n.
void	ft_print_combn(int n)
{
	char combination[n];

	ft_combine(combination, n, 0, 0);
}
// Pour tester le résultat
int main()
{
	int n = 1;
	while (n < 10)
		ft_print_combn(n++);
	return (0);
}

// Les nombres premiers ne sont JAMAIS pairs, chiffre 2 exclu.
// Pour savoir si un nombre est premier, on peut tester si les modulos de tous les nombres impairs (un nombre pair avec modulo de 2 renverra toujours 0)
// avant la racine carrée dudit nombre nous renvoient 0.
// Si ça renvoie 0, cela veut dire qu'il n'est pas divisible que par lui même et par 1.
// Evidemment, on ne doit pas tester le nombre lui-même.
// J'ai mis n < nb / 2 car c'est une limite satisfaisante pour les tests.
// COmme dit plus haut, on pourrait essayer de calculer une approximation de la racine carrée de nb, mais j'avais la flemme.
// On pourrait d'ailleurs ne tester que si le nombre est divisible sans reste par les nombres premiers qui le précèdent
// Mais cela demanderait... de connaître tous les nombres premiers qui précèdent le nombre à tester.
// Pour tester si votre fonction renvoie le bon résultat : http://compoasso.free.fr/primelistweb/page/prime/liste_online_en.php
// Ne pas oublier de faire time ./a.out
// Dépasser les 2 / 3 secondes, c'est RIP.
int	ft_is_prime(int nb)
{
	int n;

	n = 3;
	if (nb < 0 || nb == 0 || nb == 1)
		return (0);
	if (nb == 2)
		return (1);
	if (!(nb & 1))
		return (0);
	while (n < nb / 2 && n <= 46340)
	{
		if (nb % n == 0 && n != nb)
			return (0);
		n += 2;
	}
	return (1);
}

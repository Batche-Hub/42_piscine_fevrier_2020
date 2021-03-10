// Attention au time out !
// Lors des tests, avant l'exécution time ./a.out
// 46340 == plus grand racine carrée (entière) qu'on peut trouver dans un int
int	ft_sqrt(int nb)
{
	int sqrt;

	sqrt = 0;
	if (nb <= 0)
		return (0);
	while (sqrt <= 46340)
	{
		if (sqrt * sqrt == nb)
			return (sqrt);
		sqrt++;
	}
	return (0);
}

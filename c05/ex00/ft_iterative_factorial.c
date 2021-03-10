// Pas grand chose à dire. Il y a sûrement plein de façon de résoudre cet exo.
int	ft_iterative_factorial(int nb)
{
	int res;
	int count;

	res = 1;
	count = 1;
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	while (count <= nb)
	{
		res = res * count;
		count++;
	}
	return (res);
}

// regarder vidéo sur les pointeurs sur fonctions. On peut utiliser pour tester putnbr
void	ft_foreach(int *tab, int length, void (*f)(int))
{
	while (length--)
		(*f)(*tab++);
}

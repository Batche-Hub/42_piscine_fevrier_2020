// voir ex02
// a noter qu'on peut considérer le 'DEL' comme non imprimable, mais team pas DEL de mon côté, c'est plus rapide.
int	ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (*str < 32)
			return (0);
		str++;
	}
	return (1);
}

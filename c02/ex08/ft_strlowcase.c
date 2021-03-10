// voir ex02

// Ici en plus de de voir savoir si un char est d'une certaine catégorie (majuscule par exemple)
// on doit changer la valeur de ce char pour le mettre dans une autre catégorie (majuscule par exemple)
char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

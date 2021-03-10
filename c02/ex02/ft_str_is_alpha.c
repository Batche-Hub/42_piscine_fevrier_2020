// man ascii

// Dans cet exercice et les suivant, on doit déterminer si une cdhaîne de caractère
// est alphabétique, numérique, non imprimable etc.
// Il faut donc check chaque caractère et vérifier selon les conditions données si tous les caractères
// sont bien alphabétique numérique ou non imprimable etc.
// Donc il faut vérifier les valeur ascii de chaque caractère
// Ici je teste directement avec le pointeur sur char (je teste le caractère pointée à l'adresse donnée)
// et j'incrémente l'adresse. On pourrait faire également autrement en incrémentant un indice.
int	ft_str_is_alpha(char *str)
{
	while (*str)
	{
		if (!((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')))
			return (0);
		str++;
	}
	return (1);
}

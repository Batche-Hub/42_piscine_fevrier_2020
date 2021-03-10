//cet exo et l'inverse de str_join. On découpe notre chaine selon un séparateur quelconque pour ranger les résultats dans un tableau de tableau.
#include <stdlib.h>
// sert à déterminer si un char fait partie de la chaîne separatrice
int		ft_is_sep(char c, char *sep)
{
	while (*sep)
	{
		if (c == *sep)
			return (1);
		sep++;
	}
	return (0);
}
// sert à compter le nombre de mots qu"on aura. utile pour malloquer notre tableau de tableau
int		nb_wrds(char *str, char *sep)
{
	int count;

	count = 0;
	while (*str)
	{
		// tant que le char fait partie du spéarateur j'incrémente
		while (*str && ft_is_sep(*str, sep))
			str++;
		//si ça ne fait pas partie de la chaîne séparatrice, j'augmente mon nombre de mot de 1, puis tant que ce n'est pas
		// un séparateur (en bref, tant que je suis dans un mot), j'incrémente ma chaîne, pour ne pas compter autant de mots
		//qu'il n'y a de lettres.
		if (!ft_is_sep(*str, sep) && *str)
		{
			count++;
			while (!ft_is_sep(*str, sep) && *str)
				str++;
		}
	}
	return (count);
}
// un strdup pimpé, qui me sert à copier mon mot à l'emplcement désiré dans ma chaîne de chaîne.
// je récupère directement l'endroit où je suis grâce à l'adresse, je n'ai pas besoin d'indiquer 
//un indice en plus. Pratique.
char	*ft_strdup(char *str, char *sep)
{
	int		i;
	char	*word;

	i = 0;
	while (!ft_is_sep(str[i], sep) && str[i])
		i++;
	if (!(word = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (str[i] && !ft_is_sep(str[i], sep))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return (word);
}
// La fonction principale.
// On calcule le nombre de mot pour malloc notre tableau de tableau, et ensuite on suit le même cheminement que pour compter les mots.
// Sauf que au lieu de compter les mots, je copie le mot dans mon tableau de tableau. L'algo est le même.
char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**tab;

	i = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * nb_wrds(str, charset) + 1)))
		return (NULL);
	while (*str)
	{
		while (*str && ft_is_sep(*str, charset))
			str++;
		if (!ft_is_sep(*str, charset) && *str)
		{
			tab[i] = ft_strdup(str, charset);
			i++;
			while (!ft_is_sep(*str, charset) && *str)
				str++;
		}
	}
	tab[i] = NULL;
	return (tab);
}

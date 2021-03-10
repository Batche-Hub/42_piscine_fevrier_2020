// Une nouvelle notion : malloc.
// malloc est une fonction qui nous permet d'allouer de l'espace mémoire.
// Jusque maintenant, l'espace alloué été fait "automatiquement" pour expliquer gorssièrement.
// Avec malloc on va pouvoir allouer une quantité désirée dans un autre emplacement de la ram, le tas.
// Si l'espace qu'on souhaite réserver n'est pas dispo, alors on protège en renvoyant un NULL, ça évite des erreurs
// Ici, nous n'avons pas besoin de libérer la mémoire une fois qu'on a utilisé notre fonction comme on souhaitait le faire
//Mais bien souvent c'est nécessaire, afin de ne pas encombrer un espace désormais devenu inutile et occasionner des fuites de mémoire.
// Ici la fonction est grossièrement ce qu'on a fait avec strcpy mais en utilisant la fonction malloc.

// Malloc retourne un pointeur sur void, il est donc conseillé (mais les avis semblent diverger), de le caster en fonction du résultat désiré.
// Ce n'est pas obligatoire.
// Ensuite, on alloue selon la taille de l'entité à créer via la fonction sizeof. Si c'est un int, sizeof(int) si c'est un char sizeof(char) etc..
// On multiplie cela par le nombre de case à allouer pour chaque entité. Dans notre cas, la taille de la chaine à copier + 1 pour le \0 terminal.
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*cpy;
	int		i;

	i = 0;
	if (!(cpy = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

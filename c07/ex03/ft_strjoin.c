// Ici on doit concaténer des chaînes qui sont originellement dans un tableau de tableau avec entre les deux un séparateur.
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
// Si size est plus petit ou égal à 0, alors je retourne une chaîne vide créée via malloc, car on doit pour "free" la chaîne, ce ne peut intervenir
// que si on crée la chaîne via malloc.
char	*ft_strempty(void)
{
	char *concat;

	concat = (char *)malloc(sizeof(char));
	*concat = 0;
	return (concat);
}
// Un strcat pimpé pour l'occasion, où on concatère notre chaîne résente à un moment donné, le séparateur puis le nouveau morceau à coller.
// count nous sert à savoir si on doit coller (ou non) un séparateur. Il y a x mots - 1 de séparateurs (on ne doit pas en mettre à la fin).
char	*ft_strcat(char *dest, char *src, char *sep, int count)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	if (count > 0)
	{
		while (sep[k])
		{
			dest[i + j + k] = sep[k];
			k++;
		}
	}
	dest[i + j + k] = '\0';
	return (dest);
}
// la fonction principale
char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		lens_size;
	int		count;
	char	*concat;

	if (size <= 0)
		return (ft_strempty());
	i = 0;
	lens_size = 0;
	while (i < size)
		lens_size += ft_strlen(strs[i++]);
	lens_size += ft_strlen(sep) * (size - 1);
	if (!(concat = (char *)malloc(sizeof(char) * lens_size + 1)))
		return (NULL);
	i = 0;
	count = size - 1;
	concat[i] = 0;
	while (i < size)
	{
		ft_strcat(concat, strs[i], sep, count);
		i++;
		count--;
	}
	return (concat);
}

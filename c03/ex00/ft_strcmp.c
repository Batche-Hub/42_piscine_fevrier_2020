// Cette fonction sert à comparer les valeur ascii entre 2 chaîne de char
// Si le résultat est négatif, s2 est plus grande que s1, dans le le cas contraire c'est l'inverse, sinon elle sont égales.
int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

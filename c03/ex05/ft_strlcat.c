// Une fonction assez horrible à saisir correctement
// En gros : si size en param est plus grande ou égale à la taille de dest, on va renvoyer la taille de cette dernière + celle de src
// Sinon on renvoit la taille de size + src
// Ca veut dire que si on à src + dest en retour de fonction et que size est strictement plus grande (pour inclure le 0 terminal)
//que ce résultat , la concaténation aura eu lieu. Sinon ça veut dire que la concaténation aura foiré.
// Ca paraît simple, mais ça ne l'est pas
unsigned int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int src_len;
	unsigned int dest_len;
	unsigned int i;

	i = 0;
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (size >= dest_len)
		src_len += dest_len;
	else
		src_len += size;
	if (size > dest_len)
	{
		while (src[i] && dest_len < size - 1)
		{
			dest[dest_len] = src[i];
			dest_len++;
			i++;
		}
	}
	dest[dest_len] = '\0';
	return (src_len);
}

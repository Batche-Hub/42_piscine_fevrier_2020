//man strlcpy (sur mac, ou sur internet, elle n'est pas présente de base sur ubuntu)
//fonction un peu relou qui sert en gros, à nous dire si une copie a été faite correctement ou non
// (aka si la résultante est tronquée par rapport à la source)
unsigned int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int len;

	i = 0;
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}

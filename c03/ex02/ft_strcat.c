//man strcat
// on doit concaténer deux chaînes. Du coup, il faut aller au bout de dest, puis copier src au bout de dest.
char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[j + i] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

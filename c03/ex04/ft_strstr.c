//façon pas opti de résoudre cet exo mais qui fonctionne plutôt bien.
//clairement améliorable
char	*ft_strstr(char *str, char *to_find)
{
	char *str_cpy;
	char *to_find_cpy;

	if (*str == '\0' && *to_find == '\0')
		return (str);
	while (*str)
	{
		to_find_cpy = to_find;
		str_cpy = str;
		while (*str == *to_find_cpy && *to_find_cpy != '\0' && *str != '\0')
		{
			to_find_cpy++;
			str++;
		}
		if (!*to_find_cpy)
			return (str_cpy);
		str = str_cpy + 1;
	}
	return (0);
}

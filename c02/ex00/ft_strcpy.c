// == Pro tip ==
// Man strcpy

// == L'exo ==
// L'idée est de copier dans dest la chaine de caractère src
// Pour tester votre fonction :
// Il faut qu'il y est un buffer assez grand afin de pouvoir copier les données de src dans dest
// C'est sale, mais vous pouvez utiliser l'option suivante :
// char dest[150];
// char src[150] = "Ma super phrase pour strcpy plzz dieu faite en sorte que ça fonction meow."
// printf("%s", dest);

// == /!\ ==
// Une chaîne de caractère se termine TOUJOURS par un zéro terminal.
// check ==> man ascii, et regardez à l'indice 0.
char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

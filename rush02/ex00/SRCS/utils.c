// ne surtout pas reproduire les codes de ce rush, c'est mauvais !
#include "ft.h"

int	error()
{
	write (1, "Dict Error\n", 12);
	return (1);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}
char	*ft_strdup(char *str)
{
	char	*cpy;
	int	len;
	int	i;

	len = ft_strlen(str);
	if (!(cpy = (char *)malloc(sizeof(int) * len + 1)))
		return (NULL);
	i = 0;
	while (str[i])
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}

char	*make_arr_char(char *path)
{
	int	fd;
	int	ret;
	char	array[BUFF + 1];
	char	*dict_cpy;

	fd = open(path, O_RDONLY);
	if(fd == -1)
		return (NULL);
	ret = read(fd, array, BUFF);
	array[ret] = '\0';
	dict_cpy = ft_strdup(array);
	if(close(fd) == -1)
		return (NULL);
	return (dict_cpy);
}

// ne surtout pas reproduire les codes de ce rush, c'est mauvais !
#include "ft.h"

int	ft_is_sep(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int		count_words(char *str, char *charset)
{
	int count;

	count = 0;
	while (*str)
	{
		if (*str && ft_is_sep(*str, charset))
		{
			while (*str && ft_is_sep(*str, charset))
					str++;
		}
		while (*str && !ft_is_sep(*str, charset))
		{
			count++;
			while (*str && *str != '\n')
				str++;
		}
	}
	return (count);
}

char	*ft_strdup_split(char *str)
{
	int		i;
	char	*word;

	i = 0;
	while (*str != '\n' && str[i])
		i++;
	if (!(word = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (str[i] && *str != '\n')
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split_numbers(char *str)
{
	int		i;
	char	**numbers;
	int		nb_words;
	int		head;
	char	*charset;

	charset = " :\n";
	nb_words = count_words(str, charset);
	i = 0;
	head = 1;
	if (nb_words & 1)
		return (NULL);
	if (!(numbers = (char **)malloc(sizeof(char *) * (nb_words / 2) + 1)))
		return (NULL);
	while (*str)
	{
		while (*str && ft_is_sep(*str, charset))
			str++;
		if (!ft_is_sep(*str, charset) && *str && (head & 1))
		{
			numbers[i] = ft_strdup_split(str);
			i++;
			head++;
			while (*str != '\n' && *str)
				str++;
		}
		else if (!ft_is_sep(*str, charset) && *str && !(head & 1))
		{
			head++;
			while(!ft_is_sep(*str, charset) && *str)
				str++;
		}
	}
	numbers[i] = NULL;
	return (numbers);
}

char    **ft_split_letters(char *str)
{
	int     i;
	char    **letters;
	int     nb_words;
	int     head;
	char    *charset;
	
	charset = " :\n";
	nb_words = count_words(str, charset);
	i = 0;
	head = 1;
	if (nb_words & 1)
		return (NULL);
	if (!(letters = (char **)malloc(sizeof(char *) * (nb_words / 2) + 1)))
		return (NULL);
	while (*str)
	{
		while (*str && ft_is_sep(*str, charset))
			str++;
		if (!ft_is_sep(*str, charset) && *str && !(head & 1))
		{
			letters[i] = ft_strdup_split(str);
			i++;
			head++;
			while (*str != '\n' && *str)
				str++;
		}
		else if (!ft_is_sep(*str, charset) && *str && (head & 1))
		{
			head++;
			while(!ft_is_sep(*str, charset) && *str)
				str++;
		}
	}
	letters[i] = NULL;
	return (letters);
}

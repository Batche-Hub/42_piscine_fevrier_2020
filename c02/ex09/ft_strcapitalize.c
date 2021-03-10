//exercice un peu plus complexe où on doit, selon les règle donner dans l'exo, formater une chaîne de char
// selon les règles.

// 1/ des fonctions qui testent la catégorie des char rencontrés.
// 2/ la fonction principale qui : met tout en minuscule ce qui est en maj
// puis selon les tests fait ce qu'elle doit faire c'est à dire : suivre les règles.
// Si vous êtes piscineux.se je vous conseille de résoudre cet exercice tout.e seul.e, c'est plus rigolo.
// Faites des tests complets, on peut avoir bon à un moment avec la moulinette, puis ensuite vouloir passer un exo plus dur et avoir faux parce que
// un autre cas de figure a été testé.

// Notez qu'on pourrait réduire le code de isnotalphanum en testant les fonctions en dessous (et en les mettant au dessus du coup, pour éviter le prototypage)
int		is_not_alphanum(char c)
{
	if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
				|| (c >= 'A' && c <= 'Z')))
		return (1);
	else
		return (0);
}

int		is_upper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

int		is_lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

int		is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	i = 0;
	while (str[i])
	{
		while (is_not_alphanum(str[i]) && str[i])
			i++;
		if (str[i] && is_lower(str[i]) && is_not_alphanum(str[i - 1])
				&& !is_upper(str[i - 1]) && !is_num(str[i - 1]))
			str[i] -= 32;
		i++;
	}
	return (str);
}

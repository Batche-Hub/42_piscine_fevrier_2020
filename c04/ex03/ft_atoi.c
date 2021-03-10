// A noter : cet implémentation N'EST PAS la même que celle de la fonction disponible sur vos ordi
// Ceci étant dit, on doit transformer une chaine de char en int, si jamais sont présents
// des char qui représentent des chiffre à partir d'un moment précis.
// Si vous êtes en piscine, rappelez-vous : on est dans la table ascii : 0 en chiffre ne correspond pas à 
// '0' en table ascii.
int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
			|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int res;
	int sign;

	res = 0;
	sign = 1;
	// tant qu'il y a des char correspond à la définition de isspace (man isspace) on incrémente
	while (*str && ft_isspace(*str))
		str++;
	// tant qu'il y a des + ou - on incrémente. Si on a des moins, à chaque rencontre on multiplie par -1 notre signe
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	//tant la chaîne existe, et que les char rencontrés sont entre 0 et 9, on fait la formule qui nous permet de passer de la valeur ascii
	// à la valeur en entier de type int.
	// Look here => https://www.geeksforgeeks.org/convert-base-decimal-vice-versa/
	// généralement ce site est un super site.
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - 48;
		str++;
	}
	return (res * sign);
}

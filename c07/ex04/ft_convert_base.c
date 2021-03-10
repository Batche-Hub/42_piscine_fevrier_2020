// Exercice très long et assez difficile à réussir.
// On doit partir d'un nombre en une base donnée et le convertir dans une autre base.
// L'idée c'est de réunir en quelque sorte atoi_base et son pendant itoa base. Je l'ai appelé pour ma part putnbr base, mais c'est pareil.
#include <stdlib.h>

int		ft_baselen(char *base);
int		check_base(char *base);
long	ft_atoi_base(char *str, char *base);
// Notre compteur pour itoa (savoir quelle sera la taille exacte de la chaîne de char finale.
int		ft_count(long nb, long baselen)
{
	int count;

	count = 2;
	if (nb < 0)
	{
		nb *= -1;
		count += 1;
	}
	while (nb >= baselen)
	{
		nb /= baselen;
		count++;
	}
	return (count);
}
// Permet d'inverser la chaîne de char, car avec "ma" façon, on écrit la fin au début et vice-versa
char	*ft_strrev(char *str)
{
	int	i;
	int	size;

	i = -1;
	size = ft_baselen(str);
	while (++i < --size)
	{
		str[i] ^= str[size];
		str[size] ^= str[i];
		str[i] ^= str[size];
	}
	return (str);
}
// Une fonction un peu useless, car je fais des codes trop longs et que je nsavais pas comment faire autrement avec itoa.
// Sert à convertir 0 dans la base_to.
char	*ft_putzero_base(char *base)
{
	int		i;
	char	*convert;
	int		baselen;

	baselen = ft_baselen(base);
	if (!(convert = (char *)malloc(sizeof(char) * ft_count(0, (long)baselen))))
		return (NULL);
	i = 0;
	convert[i] = 0;
	convert[i] = base[0 % baselen];
	i++;
	convert[i] = 0;
	return (convert);
}
// itoa
char	*ft_putnbr_base(long nbr, char *base)
{
	int		i;
	int		sign;
	int		baselen;
	char	*convert;

	sign = 1;
	baselen = ft_baselen(base);
	i = 0;
	if (!(convert = (char *)malloc(sizeof(char) * ft_count(nbr, baselen))))
		return (NULL);
	convert[i] = 0;
	(nbr < 0) ? sign *= -1 : sign;
	(nbr < 0) ? nbr *= -1 : nbr;
	while (nbr)
	{
		convert[i] = base[nbr % baselen];
		nbr /= baselen;
		i++;
	}
	sign == -1 ? convert[i] = '-' : convert[i];
	sign == -1 ? i++ : i;
	convert[i] = 0;
	ft_strrev(convert);
	return (convert);
}
// la fonction principale
char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int cpy;

	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	cpy = ft_atoi_base(nbr, base_from);
	if (cpy == 0)
		return (ft_putzero_base(base_to));
	return (ft_putnbr_base(cpy, base_to));
}

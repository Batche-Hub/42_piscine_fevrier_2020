// == /!\ ==
// Si tu es piscineux.se et nouveau/nouvelle en code : cet exercice est plus compliqué que les précédents
// Si tu ne vois pas comment le faire, que tu ne connais pas comment passer d'une base à un autre
// Que ça te semble difficile, inutile de faire l'exercice maintenant, tu pourras y revenir plus tard
//en ayant acquis les connaissances nécessaire à sa résolution ! ==> check c04 qui aide énormément

// Alors exercice assez bizarre, où on manipule des char qu'on caste (càd qu'on met dans un autre type que celui de base)
// afin de pouvoir imprimer les char non imprimable en ayant auparavant transofrmé ces char dans leur valeur ascii en
// hexadécimal.
#include <unistd.h>

void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

int		is_no_printable(unsigned char c)
{
	if (c < 32 || c > 126)
		return (1);
	else
		return (0);
}
// La fonction qui sert à mettre en base 16. Ressemble énormément à putnbr. C'est le même principe, si ce n'est qu'ici on sait qu'on ne va pas
// dépasser 16 en taille. On divise et modulo pou autmatiquement mettre un 0 avant chaque version hexa.
void	convert_to_hex(unsigned char c)
{
	char *hex;

	hex = "0123456789abcdef";
	ft_putchar('\\');
	ft_putchar(hex[(unsigned char)c / 16]);
	ft_putchar(hex[(unsigned char)c % 16]);
}
// la fonction de base
void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (is_no_printable((unsigned char)*str))
			convert_to_hex((unsigned char)*str);
		else
			ft_putchar((unsigned char)*str);
		str++;
	}
}

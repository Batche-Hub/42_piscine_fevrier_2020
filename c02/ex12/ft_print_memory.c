// exercice TRES difficile en piscine.
// Ne pas le faire si on ne se sent pas de le faire

// L'idée est de singer la mémoire et de montrer :
// 1) La valeur de l'addresse des char, tous les 16 chars, en hexadécimal
// 2) Par paire de deux, imprimer dans leur valeur hexadécimal des char
// 3) imprimer les dits char normalement, sauf pour les nom imprimable en les remplaçant par des '.'

// En soi, la partie concernant les impressions (mettre l'adresse en hexa, les chars en hexa etc.)
// ne pose pas trop de problème une fois qu'on comprend qu'un pointeur sur void est une sorte de cellule souche du code en C ^_^

// Par contre, la partie concernant la mise en forme de tout ça est clairement le plus relou, et il m'aura fallu du temps et beaucoup d'échange de code
// et de discussion avec une camarade de piscine afin d'arriver à bout de cet exo.
// On m'informe dans l'oreillette que c'est faux : j'ai eu 0 car j'ai laissé unez variable inutile dans mon code.
// :((((((((((((

// Bref !
#include <unistd.h>

void	ft_putchar(unsigned char c)
{
	if (c < 32 || c > 126)
		write(1, ".", 1);
	else
		write(1, &c, 1);
}
// CHanger l'adresse en hex. Adresse qu'on a en size_t, aka, unsigned long int
void	to_hex(size_t addr)
{
	char *hex;

	hex = "0123456789abcdef";
	if (addr >= 16)
		to_hex(addr / 16);
	ft_putchar(hex[addr % 16]);
}
// Une autre fonction pour l'adresse, en gros qui me sert à faire un compteur
// Pour savoir le nombre de 0 qu'il y aura en fonction de l'adresse en base 16 (hexa)
// Adresse que j'envoie, une fois les 0 imprimés, dans la fonction au dessus.
void	address_to_hex(void *addr)
{
	size_t	cpy;
	size_t	nbr;
	int		count;
	int		remain;

	count = 1;
	cpy = (size_t)addr;
	nbr = cpy;
	while (cpy >= 16)
	{
		cpy /= 16;
		count++;
	}
	remain = 16 - count;
	while (remain--)
		ft_putchar('0');
	to_hex(nbr);
	ft_putchar(':');
}
// Fonction qui changeles char en hex, c'est l'enfer.
// On est limités par la taille du code, aussi il y a des ternaires partout ce qui rend le code assez illisible, sorry
void	char_to_hex(unsigned char *c, unsigned int size)
{
	char			*hex;
	unsigned int	i;
	unsigned int	n;

	i = 0;
	hex = "0123456789abcdef";
// Ici, en fonction de la taille à imprimer (size, qu'on calcule dans la fonction principale en fonction de la taille donnée en
// paramètre de ladite fonction principale)
// on imprime par paire de deux les char, puis toutes les deux paires, on ajouter un espace
	while (i < size)
	{
		(i % 2 == 0) ? write(1, " ", 1) : write(1, "", 0);
		ft_putchar(hex[c[i] / 16]);
		ft_putchar(hex[c[i] % 16]);
		i++;
	}
	i = 0;
	//si on est à la fin d'une série de 16, on imprime un espace.
	//c'est très moche :s
	(size == 16) ? write(1, " ", 1) : write(1, "", 0);
	//Si la size envoyé en paramètre est plus petite que 16 (c'est à dire qu'on est arrivé à la fin de ce qu'on doit imprimer)
	// alors il faut compléter d'espaces ce qui aurait été imprimé si jamais on avait un multiple de 16
	// càd qu'il faut tout aligner : adresse avec adresse, char to hex avec char to hex et char avec char.
	// L'exemple que j'avais eu sur le pdf était bugué, peut-être est-ce le cas encore aujourd'hui.
	// Ne pas se fier donc aux exemple où tout est décalé.
	if (size < 16)
	{
		n = ((16 - size) * 2);
		if (!(size & 1))
			ft_putchar(' ');
		while (n--)
			write(1, "  ", (n % 4 == 0 ? 2 : 1));
	}
	while (i < size)
		ft_putchar(c[i++]);
}
// La fonction principale, ou on envoie des charettes de 16 char aux fonctions ci-dessus
void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	print_size;
	char			*add_str;

	add_str = addr;
	i = 0;
	print_size = 16;
	while (i < size)
	{
		print_size = (size - i >= 16) ? 16 : size - i;
		address_to_hex(add_str + i);
		char_to_hex((unsigned char *)add_str + i, print_size);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}

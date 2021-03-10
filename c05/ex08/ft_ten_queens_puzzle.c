// == /!\ ==
// Cet exercie est assez difficile. Si vous ne comprenez pas, ne faite pas et revenez dessus plus tard, ou alors travaillez le un peu tous les jours.

// Pour avoir une début de réponse sur ce problème, visitez ce site ==> https://www.geeksforgeeks.org/n-queen-problem-backtracking-3/
// Ca explique assez bien l'idée derrière ce problème.

// Dans le backtracking, l'important, c'est les REGLES.
// En soi le backtracking (le coder, pas à comprendre exactement ce qui se passe au niveau de la machine) n'est pas très difficile à saisir.
// Ce qui l'est plus, c'est de déterminer les règles qui vont faire que notre backtracking arrive à la solution demandée.
// Lorsque j'avais fait cet exo pour la première fois, j'ai eu un moment plus de 2 milliards de solutions.
// SPOIL : c'est faux
// Il y en a un peu moins.

// Je vais expliquer le code, j'aime beaucoup cet exercice
#include <unistd.h>
// Fonction qui nous sert à imprimer l'échiquier. A noter que pour ma part je passe par un tableau unidimensionnel,
// on pourrait probablement le faire avec un double tableau et ensuite le "mettre" en une dimension. Pour ma part je trouve ça plus "simple"
// comme ça.
void	print_puzzle(int board[10])
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = board[i] + 48;
		write(1, &c, 1);
		i++;
		if (i == 10)
			write(1, "\n", 1);
	}
}
// Une fonction qui détermine la valeur absolue d'un nombre
int		ft_abs(int n)
{
	return ((n < 0) ? n *= -1 : n);
}
// La fonction des règles, qui va régir notre backtracking.

// Nous ne testons que les colonnes à gauche de là où nous nous trouvons à un instant T.
// imaginons la chose suivante :

// Mon board (en 2d, pour faciliter la représentation visuelle de la chose) est pour l'instant ça :

// 9	0 0 0 0 0 0 0 0 0 0
// 8	0 0 0 0 0 0 0 0 0 0
// 7	0 0 0 0 0 0 0 0 0 0
// 6	0 0 0 0 0 0 0 0 0 0
// 5	0 0 x 0 0 0 0 0 0 0
// 4	0 0 0 0 0 0 0 0 0 0
// 3	0 0 0 x 0 0 0 0 0 0
// 2	0 x 0 0 0 0 0 0 0 0
// 1	0 0 0 0 0 0 0 0 0 0
// 0	x 0 0 0 0 0 0 0 0 0
	
//	0 1 2 3 4 5 6 7 8 9

//	Je viens de placer la reine en  (3, 3). Le chiffre de de gauche étant la colonne, celui de droite la ligne.
//	J'ai des reines respectivement en (0, 0), (1, 2), (2, 5)
//	Je veux tester si je la reine peut se faire manger à la place où elle est.
// Je dois donc tester : à gauche, sur la même ligne, en diagonale bas par rapport à sa place, ainsi qu'en diagonale haut.

// L'idée, c'est de savoir le rapport qu'entretien une place avec une autre potentiellement dangeureuse pour elle.

// Pour les places sur la même ligne, c'est simple : je dois savoir si à une colonne donnée, j'ai la même valeur de ligne.

// Ainsi si jamais par exemple une reine en (2, 3), l'endroit ne serait pas sûr, car j'ai la même valeur de ligne dans la colonne 2 et la colonne 3.

// Pour les diagonales, je dois calculer si à une colonne donnée, j'ai une valeur de ligne qui correspond à la valeur de ma ligne testée + || -
// la valeur absolue de la valeur de colonne de gauche moins la valeur de la colonne courante.
// Donc je suis en colonne 3, ligne 3.

// Je dois tester la colonne 2.

// Diagonale haut ça donne : 3 + absolu de 2 - 3 = ce qui donne 4.
// Je dois donc voir si à la colonne 2 j'ai la valeur 4 pour la ligne, autrement dit s'il y a une reine en (2, 4)

// Diagonale bas ça donne : 3 - absolu de 2 - 3 = ce qui donne 2.
// Je dois donc voir si à la colonne 2 j'ai la valeur 2 pour la ligne, autrement dit s'il y a une reine en (2, 2)

// Et ainsi de suite.

// Dans l'exemple plus haut, ma reine n'est pas en sûreté, car à la colonne 0 ligne 0 j'ai une reine :
// 3 - absolu de 0 - 3 = ce qui donne 0.
// (0, 0) == reine
// Je dois donc tester une autre valeur, ce qui se fait avec la fonction de backtracking plus bas.
int		staying_safe(int board[10], int column, int row)
{
	int left;

	left = column - 1;
	while (left >= 0 && column != 0)
	{
		if (board[left] == row + ft_abs(left - column))
			return (0);
		if (board[left] == row - ft_abs(left - column))
			return (0);
		if (board[left] == row)
			return (0);
		left--;
	}
	return (1);
}
// La voici la voilà.
// Assez simple, si ma fonction qui teste si la place est sûr renvoie 1, ça veut dire que je peux placer ma dame,
// je peux poursuivre via une récursion en incrémentant la valeur de ma clonne (afin d'avancer)
// Si j'arrive à 10 en valeur de colonne, ça veut dire que tous mes résultats sont bons, donc je peux imprimer le board.
// Si ma fonction de sûreté men renvoie 0, la place n'est pas sûr, je backtrack et je teste une autre valeur (enfin l'ordi, pas nous, ouf !)
int		solve_puzzle(int board[10], int column, int *victory)
{
	int row;

	row = 0;
	if (column == 10)
	{
		print_puzzle(board);
		*victory += 1;
		return (1);
	}
	while (row < 10)
	{
		if (staying_safe(board, column, row))
		{
			board[column] = row;
			solve_puzzle(board, column + 1, victory);
			board[column] = -1;
		}
		row += 1;
	}
	return (0);
}
// Ici la fonction principale, où on met l'adresse de l'int victory afin de pouvoir l'incrémenter durant les récursions et renvoyer la valeur.
int		ft_ten_queens_puzzle(void)
{
	int victory;
	int board[10];
	int column;

	column = 0;
	victory = 0;
	solve_puzzle(board, column, &victory);
	return (victory);
}

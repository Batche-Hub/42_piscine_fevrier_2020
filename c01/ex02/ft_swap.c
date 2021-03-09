// Cette fonction très utile permet "d'échanger la valeur deux deux adresses pointée.
// == Expérience de pensée ==
// Si je n'ai pas un nombre temporaire, et que je fais *a = *b et *b = *a
// et que a = 2 et b = 4, combien vaudront b et a à la fin ?
void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

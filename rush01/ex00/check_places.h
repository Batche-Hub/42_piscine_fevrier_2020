#ifndef CHECK_PLACES_H
# define CHECK_PLACES_H

int		check_norm_col(int tab[6][6]);

int		check_rev_col(int tab[6][6]);

int		check_norm_row(int tab[6][6]);

int		check_rev_row(int tab[6][6]);

int		is_possible(int tab[6][6], int col, int row, int place);

#endif

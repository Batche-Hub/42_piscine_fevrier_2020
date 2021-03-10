#ifndef FT_H
# define FT_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# define BUFF 4096

int		error();

int		ft_strlen(char *str);

void	ft_putstr(char *str);

char	*ft_strdup(char *str);

char	*make_arr_char(char *path);

int		ft_is_sep(char c, char *charset);

int		count_words(char *str, char *charset);

char	*ft_strdup_split(char *str);

char	**ft_split_numbers(char *str);

char    **ft_split_letters(char *str);

#endif

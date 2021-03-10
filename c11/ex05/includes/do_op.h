// mon header, avec tous les protos + phrases à afficher quand / 0 ou % 0
#ifndef DO_OP_H
# define DO_OP_H
# include <unistd.h>
# define STOPDIV "Stop : division by zero\n"
# define STOPMOD "Stop : modulo by zero\n"

void	ft_putchar(char c);

void	ft_putstr(char *str);

void	ft_putnbr(int nb);

int		check_op(char *str);

void	prepare_op(char *num1, char *operande, char *num2);

void	do_op(int number1, int operation, int number2);

int		ft_isspace(char c);

int		ft_atoi(char *str);

int		add(int a, int b);

int		minus(int a, int b);

int		multiply(int a, int b);

int		divide(int a, int b);

int		modulo(int a, int b);

#endif

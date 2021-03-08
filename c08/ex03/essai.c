#include "ft_point.h"

void	set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}
#include <stdio.h>
int	main(void)
{
	t_point	point;
	set_point(&point);
	printf("point.x = %d\npoint.y = %d\n", point.x, point.y);
	return (0);
}

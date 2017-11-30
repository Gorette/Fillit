#include "fillit.h"

int		ft_map(t_rex **start)
{
	char	**map;
	t_rex	*first;
	int		size;
	int		i;
	int		select;

	i = 0;
	first = *start;
	if (first->h >= first->l)
		size = first->h;
	else
		size = first->l;
	if (!(map = (char **)malloc(sizeof(char *) * size + 1)))
		return (1);
	while (i < size)
	{
		select = 0;
		if (!(map[i] = (char *)malloc(sizeof(char) * size + 1)))
			return (1);
		while (select < size)
		{
			map[i][select] = '.';
			select++;
		}
		map[i][select] = '\0';
		i++;
	}
	map[size] = NULL;
	ft_print_tab(map);
	return (0);
}

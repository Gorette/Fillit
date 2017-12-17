/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:16:36 by axbal             #+#    #+#             */
/*   Updated: 2017/12/09 14:26:07 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_del_tetri(t_rex *tetri, char **map)
{
	char	c;
	int		i;
	int		j;
	int		count;

	count = 0;
	i = 0;
	j = 0;
	while (j < 4 && tetri->tab[0][j] == '.')
		j++;
	c = tetri->tab[0][j];
	while (count < 4 && map[i])
	{
		j = 0;
		while (map[i][j] && count < 4)
		{
			if (map[i][j] == c)
			{
				map[i][j] = '.';
				count++;
			}
			j++;
		}
		i++;
	}
}

int		ft_fill(int x, int y, char **map, t_rex *tetri)
{
	int		i;
	int		j;
	int		cont;

	cont = 0;
	j = 0;
	while (map[y + j] && j < 4 && cont < 4)
	{
		i = 0;
		while (map[y + j][x + i] && cont < 4 && i < 4)
		{
			if (cont < 4 && tetri->tab[j][i] != '.' && map[y + j][x + i] == '.')
			{
				map[y + j][x + i] = tetri->tab[j][i];
				cont++;
				if (cont == 4)
					return (0);
			}
			i++;
		}
		j++;
	}
	ft_del_tetri(tetri, map);
	return (1);
}

void	ft_freemap(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**ft_upmap(char **map, int size)
{
	int		i;
	int		j;

	i = 0;
	ft_freemap(map);
	if (!(map = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		j = 0;
		if (!(map[i] = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		while (j < size)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	map[size] = NULL;
	return (map);
}

int		ft_size_map(t_rex **start)
{
	int		size;
	int		nb;
	t_rex	*ptr;

	nb = 1;
	size = 1;
	ptr = *start;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		nb++;
	}
	while (size * size < nb * 4)
		size++;
	return (size);
}

int		ft_map(t_rex **start)
{
	char	**map;
	t_rex	*first;
	int		size;
	int		i;
	int		select;

	i = 0;
	first = *start;
	size = ft_size_map(start) - 1;
	if (!(map = (char **)malloc(sizeof(char *) * size + 1)))
		return (1);
	while (i < size)
	{
		select = -1;
		if (!(map[i] = (char *)malloc(sizeof(char) * size + 1)))
			return (1);
		while (++select < size)
			map[i][select] = '.';
		map[i][select] = '\0';
		i++;
	}
	map[size] = NULL;
	ft_call_rec(start, map, size);
	return (0);
}

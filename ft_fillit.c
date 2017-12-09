/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 14:26:15 by axbal             #+#    #+#             */
/*   Updated: 2017/12/09 14:27:55 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_rec(t_rex *tetri, char **map, int size)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_fill(j, i, map, tetri) == 0)
			{
				if (tetri->next == NULL || ft_rec(tetri->next, map, size) == 0)
					return (0);
				ft_del_tetri(tetri, map);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_call_rec(t_rex **start, char **map, int size)
{
	t_rex	*stmp;
	int		i;

	i = 0;
	while (ft_rec(*start, map, size) != 0)
	{
		size++;
		map = ft_upmap(map, size);
	}
	while (*start)
	{
		stmp = (*start)->next;
		while ((*start)->tab[i])
		{
			free((*start)->tab[i]);
			i++;
		}
		(*start)->next = NULL;
		free(*start);
		*start = stmp;
	}
	ft_print_tab(map);
	ft_freemap(map);
	ft_putchar('\n');
}

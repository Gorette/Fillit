/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetri_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 14:20:36 by axbal             #+#    #+#             */
/*   Updated: 2017/12/09 14:22:18 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_left(t_rex *bob)
{
	int		i;
	int		select;
	char	stamp;

	i = 0;
	while (i < 4 && bob->tab[i][0] != '#')
	{
		i++;
		if (i == 4)
		{
			i = 0;
			while (i < 4)
			{
				select = -1;
				while (++select < 3)
				{
					stamp = bob->tab[i][select];
					bob->tab[i][select] = bob->tab[i][select + 1];
					bob->tab[i][select + 1] = stamp;
				}
				i++;
			}
			i = 0;
		}
	}
}

void		ft_up(t_rex *bob)
{
	int		i;
	int		select;
	char	*stamp;

	i = 0;
	select = 0;
	while (select < 4 && bob->tab[0][select] != '#')
	{
		select++;
		if (select == 4)
		{
			while (i < 3)
			{
				stamp = bob->tab[i];
				bob->tab[i] = bob->tab[i + 1];
				bob->tab[i + 1] = stamp;
				i++;
			}
			i = 0;
			select = 0;
		}
	}
}

void		ft_alphabetyzer(t_rex *bob, char c)
{
	int		i;
	int		j;

	i = -1;
	while (bob->tab[++i])
	{
		j = -1;
		while (bob->tab[i][++j])
		{
			if (bob->tab[i][j] == '#')
				bob->tab[i][j] = c;
		}
	}
}

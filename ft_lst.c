/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:58:08 by axbal             #+#    #+#             */
/*   Updated: 2017/11/28 17:25:46 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_largeur(char **tetri)
{
	int		i;
	int		j;
	int		start;
	int		end;

	i = -1;
	start = 5;
	end = 0;
	j = -1;
	while (++i < 4)
	{
		while (tetri[i][++j])
		{
			if (tetri[i][j] == '#')
			{
				if (j < start)
					start = j;
				if (j > end)
					end = j;
			}
		}
		j = -1;
	}
	return ((end - start) + 1);
}

int			ft_hauteur(char **tetri)
{
	int		i;
	int		j;
	int		h;
	int		levier;

	i = -1;
	h = 0;
	while (++i < 4)
	{
		j = -1;
		while (tetri[i][++j])
		{
			if (levier == 0 && tetri[i][j] == '#')
			{
				levier = 1;
				h++;
			}
		}
		levier = 0;
	}
	return (h);
}

void		ft_left(t_rex *bob)
{
	int		i;
	int		select;
	char	stamp;

	i = 0;
	select = 0;
	while (i < 4 && bob->tab[i][0] != '#')
	{
		i++;
		if (i == 4)
		{
			i = 0;
			while (i < 4)
			{
				while (select < 3)
				{
					stamp = bob->tab[i][select];
					bob->tab[i][select] = bob->tab[i][select + 1];
					bob->tab[i][select + 1] = stamp;
					select++;
				}
				i++;
				select = 0;
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

void		ft_rexaddend(t_rex **start, t_rex *new)
{
	t_rex	*stamp;

	if (start)
	{
		stamp = *start;
		while (stamp->next)
			stamp = stamp->next;
		stamp->next = new;
	}
	else
		start = &new;
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

void		ft_show_list(t_rex **start)
{
	t_rex	*tmp;

	tmp = *start;
	while (tmp)
	{
		ft_print_tab(tmp->tab);
		ft_putstr("\nlargeur = ");
		ft_putnbr(tmp->l);
		ft_putstr("\nhauteur = ");
		ft_putnbr(tmp->h);
		ft_putchar('\n');
	}
}

t_rex		*ft_new_tetri(char *buf)
{
	t_rex	*new;

	if (!(new = (t_rex *)malloc(sizeof(t_rex))))
		return (NULL);
	new->tab = ft_strsplit(buf, '\n');
	new->h = ft_hauteur(new->tab);
	new->l = ft_largeur(new->tab);
	new->next = NULL;
	return (new);
}

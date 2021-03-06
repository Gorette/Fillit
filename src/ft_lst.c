/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:58:08 by axbal             #+#    #+#             */
/*   Updated: 2018/01/16 13:24:08 by axbal            ###   ########.fr       */
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

void		ft_rexaddend(t_rex **start, t_rex *new)
{
	t_rex	*stamp;

	stamp = *start;
	while (stamp->next != NULL)
		stamp = stamp->next;
	stamp->next = new;
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
		tmp = tmp->next;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugene <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:46:31 by axbal             #+#    #+#             */
/*   Updated: 2017/11/28 17:27:54 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_dyez(char *str, int i)
{
	int		contact;

	contact = 0;
	if (str[i - 1] && str[i - 1] == '#')
		contact++;
	if (str[i + 1] && str[i + 1] == '#')
		contact++;
	if (str[i - 5] && str[i - 5] == '#')
		contact++;
	if (str[i + 5] && str[i + 5] == '#')
		contact++;
	return (contact);
}

int		ft_check_chars(char *str, int ret)
{
	int		line;
	int		select;
	int		i;
	int		pwin;
	int		dyez;
	int		count;

	count = 0;
	pwin = 0;
	dyez = 0;
	line = 1;
	select = 1;
	i = 0;
	while (str[i])
	{
		if (select != 5)
		{
			if (line == 5)
			{
				if (ret == 21 && str[i] != '\0' && str[i] != '\n')
					return (1);
			}
			else
			{
				if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
					return (1);
			}
			if (str[i] == '.')
				pwin++;
			if (str[i] == '#')
			{
				if ((ft_check_dyez(str, i)) < 1)
					return (1);
				count = count + ft_check_dyez(str, i);
				dyez++;
			}
		select++;
		i++;
		}
		else
		{
			if ((i == 4 || i == 9 || i == 14 || i == 19) && str[i] != '\n')
				return (1);
			else
			{
				select = 1;
				i++;
				line++;
			}
		}
	}
	if (pwin != 12 || dyez != 4)
		return (1);
	if (count < 6)
		return (1);
	return (0);
}

int		ft_read(char *str)
{
	int		fd;
	int		ret;
	char	buf[22];
	int		levier;
	t_rex	*test;

	levier = 0;
	fd = open(str, O_RDONLY);
	while ((ret = read(fd, buf, 21)) > 0)
	{
		buf[ret] = '\0';
		if (ret == 20)
			levier = 1;
		if (ft_check_chars(buf, ret) == 1)
			return (1);
		test = ft_new_tetri(buf);
		ft_print_tab(test->tab);
		ft_putstr("\nlargeur = ");
		ft_putnbr(test->l);
		ft_putstr("\nhauteur = ");
		ft_putnbr(test->h);
		ft_putchar('\n');
	}
	if (levier == 0)
		return (1);
	close(fd);
	return (0);
}

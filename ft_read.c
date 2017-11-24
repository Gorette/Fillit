/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:46:31 by axbal             #+#    #+#             */
/*   Updated: 2017/11/23 16:37:44 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_chars(char *str)
{
	int		line;
	int		select;
	int		i;
	int		pwin;
	int		dyez;

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
				if (str[i] != '\0' && str[i] != '\n')
				{
					ft_putchar(str[i]);
					ft_putstr("\nfin de tetrimino incorrecte\n");
					return (1);
				}
			}
			else
			{
				if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
				{
					ft_putchar(str[i]);
					ft_putstr("\ncaractere incorrect\n");
					return (1);
				}
			}
			if (str[i] == '.')
				pwin++;
			if (str[i] == '#')
				dyez++;
		select++;
		i++;
		}
		else
		{
			if ((i == 4 || i == 9 || i == 14 || i == 19) && str[i] != '\n')
			{
				ft_putchar(str[i]);
				ft_putstr("\npas de retour a la fin de ligne\n");
				return (1);
			}
			else
			{
				select = 1;
				i++;
				line++;
			}
		}
	}
	ft_putstr("points puis diez : ");
	ft_putnbr(pwin);
	ft_putchar(' ');
	ft_putnbr(dyez);
	ft_putchar('\n');
	if (pwin != 12 || dyez != 4)
	{
		ft_putstr("nombres incorrects\n");
		return (1);
	}
	return (0);
}

int		ft_read(char *str)
{
	int		fd;
	int		ret;
	char	buf[22];

	fd = open(str, O_RDONLY);
	while ((ret = read(fd, buf, 21)) > 0)
	{
		buf[ret] = '\0';
		ft_putstr(buf);
		if (ft_check_chars(buf) == 1)
			return (1);
	}
	close(fd);
	return (0);
}

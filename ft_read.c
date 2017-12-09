/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:46:31 by axbal             #+#    #+#             */
/*   Updated: 2017/12/09 14:19:28 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_contact(char *str, int i)
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

int		ft_check_dyez(char *str)
{
	int		i;
	int		count;
	int		contact;

	i = 0;
	count = 0;
	contact = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			count++;
			contact = contact + ft_contact(str, i);
		}
		i++;
	}
	if (count == 4 && contact >= 6)
		return (0);
	return (1);
}

int		ft_check_pattern(char *str)
{
	int		i;
	int		j;
	int		line;

	i = 0;
	line = 1;
	while (line < 5)
	{
		j = -1;
		while (++j < 4)
		{
			if (str[i] != '.' && str[i] != '#')
				return (1);
			i++;
		}
		if (str[i] != '\n')
			return (1);
		i++;
		line++;
	}
	if (str[i] == '\n' && str[i + 1] == '\0')
		return (0);
	if (str[i] != '\n' && str[i] != '\0')
		return (1);
	return (0);
}

t_rex	*ft_tetricheck(char *buf, char c)
{
	t_rex	*new;
	if (ft_check_dyez(buf) == 1 || ft_check_pattern(buf) == 1)
		return (NULL);
	new = ft_new_tetri(buf);
	ft_up(new);
	ft_left(new);
	ft_alphabetyzer(new, c);
	return (new);
}

int		ft_read(int fd, t_rex **list, char c, char *buf)
{
	int		ret;
	int		levier;
	t_rex	*new;
	t_rex	*start;

	levier = 0;
	while ((ret = read(fd, buf, 21)) > 0)
	{
		buf[ret] = '\0';
		if (ret == 20)
			levier = 1;
		if ((new = ft_tetricheck(buf, c)) == NULL)
			return (1);
		if (c++ == 'A')
		{
			start = new;
			list = &start;
		}
		else
			ft_rexaddend(list, new);
	}
	if (levier == 0)
		return (1);
	ft_map(list);
	return (0);
}

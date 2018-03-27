/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:51:26 by axbal             #+#    #+#             */
/*   Updated: 2017/12/08 14:18:45 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_error(void)
{
	write(1, "error\n", 6);
	return (0);
}

int		main(int argc, char **argv)
{
	int		ret;
	int		fd;
	char	c;
	char	buf[22];
	t_rex	**list;

	list = NULL;
	c = 'A';
	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	ret = ft_read(fd, list, c, buf);
	close(fd);
	if (ret != 0)
		return (ft_error());
	return (0);
}

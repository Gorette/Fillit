/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:51:26 by axbal             #+#    #+#             */
/*   Updated: 2017/11/23 16:14:20 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_error(void)
{
	write(2, "error\n", 6);
	return (0);
}

int		main(int argc, char **argv)
{
	int		ret;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	ret = ft_read(argv[1]);
	ft_putnbr(ret);
	return (0);
}

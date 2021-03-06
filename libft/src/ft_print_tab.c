/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:01:40 by axbal             #+#    #+#             */
/*   Updated: 2017/11/17 13:08:30 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (i != 0)
			ft_putchar('\n');
		ft_putstr(tab[i]);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:47:38 by axbal             #+#    #+#             */
/*   Updated: 2017/11/23 16:06:46 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "Libft/libft.h"
# include <fcntl.h>

typedef struct		s_tetri
{
	char			**tab;
	int				h;
	int				l;
	struct s_tetri	*next;
}					t_tetri;

int		ft_read(char *str);

#endif

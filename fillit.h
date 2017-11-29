/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:47:38 by axbal             #+#    #+#             */
/*   Updated: 2017/11/28 16:58:19 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "Libft/libft.h"
# include <fcntl.h>

typedef struct		s_rex
{
	char			**tab;
	int				h;
	int				l;
	struct s_rex	*next;
}					t_rex;

int		ft_read(char *str);
int		ft_check_chars(char *str, int ret);
int		ft_check_dyez(char *str, int i);
t_rex	*ft_new_tetri(char *buf);
void	ft_left(t_rex *bob);
void	ft_up(t_rex *bob);
void	ft_rexaddend(t_rex **start, t_rex *nw);
void	ft_alphabetyzer(t_rex *bob, char c);
void	ft_show_list(t_rex **start);

#endif

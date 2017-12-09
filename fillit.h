/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:47:38 by axbal             #+#    #+#             */
/*   Updated: 2017/12/09 14:33:06 by axbal            ###   ########.fr       */
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

int		ft_read(int fd, t_rex **list, char c, char *buf);
int		ft_check_chars(char *str, int ret, int pwin, int dyez);
int		ft_check_dyez(char *str);
t_rex	*ft_new_tetri(char *buf);
void	ft_left(t_rex *bob);
void	ft_up(t_rex *bob);
void	ft_rexaddend(t_rex **start, t_rex *nw);
void	ft_alphabetyzer(t_rex *bob, char c);
void	ft_show_list(t_rex **start);
int		ft_map(t_rex **start);
void	ft_call_rec(t_rex **start, char **map, int size);
char	**ft_upmap(char **map, int size);
void	ft_freemap(char **map);
int		ft_fill(int x, int y, char **map, t_rex *tetri);
void	ft_del_tetri(t_rex *tetri, char **map);

#endif

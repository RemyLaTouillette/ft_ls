/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 01:37:26 by sduprey           #+#    #+#             */
/*   Updated: 2016/11/12 05:30:48 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <libft.h>

# include <dirent.h>
# include <errno.h>
# include <sys/stat.h>
// CHEAT
#include <stdio.h>

typedef struct		s_ls
{
	int				l;
	int				a;
	int				r;
	int				ur;
	int				t;
	struct s_elem	*dir;
	struct s_elem	*file;
	struct s_elem	*err;
}					t_ls;

typedef struct		s_elem
{
	char			*name;
	char			type;
	struct s_elem	*next;
	//struct s_elem	*down;
}					t_elem;

int					get_options(int ac, char **av, t_ls *ls);

void				get_arguments(int ac, char **av, int i, t_ls *ls);

t_elem				*new_element(char *name);
t_elem				*add_element(t_elem *top, char *name);
void				order_elements(t_elem *top);
void				print_elements(t_elem *top);
#endif

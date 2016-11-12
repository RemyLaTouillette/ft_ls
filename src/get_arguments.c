/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 05:04:51 by sduprey           #+#    #+#             */
/*   Updated: 2016/11/12 05:30:49 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	get_arguments(int ac, char **av, int i, t_ls *ls)
{
	DIR		*dir;

	while (i < ac)
	{
		if ((dir = opendir(av[i])) != NULL)
		{
			ls->dir = add_element(ls->dir, av[i]);
			if (closedir(dir) == -1)
			{
				ft_putendl("ft_ls: error: closedir()");
				exit(-1);
			}
		}
		else
		{
			if (errno == ENOENT)
				ls->err = add_element(ls->err, av[i]);
			else if (errno == ENOTDIR)
				ls->file = add_element(ls->file, av[i]);
			else if (errno == EACCES)
				ls->dir = add_element(ls->dir, av[i]);
		}
		i++;
	}
}

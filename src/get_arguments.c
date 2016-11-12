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
	struct stat	st;

	(void)ls;
	while (i < ac)
	{
		//ft_putendl(av[i]);
		if ((lstat(av[i], &st)) != -1)
		{
			ft_putstr("OK: ");
			ft_putendl(av[i]);
		}
		else
		{
			if (errno == ENOENT)
			{
				ft_putstr(av[i]);
				ft_putendl(": add err list");
			}
		}
		i++;
	}

}

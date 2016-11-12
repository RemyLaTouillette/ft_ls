/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 05:04:51 by sduprey           #+#    #+#             */
/*   Updated: 2016/11/12 05:18:57 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	get_arguments(int ac, char **av, int i, t_ls *ls)
{
	DIR				*dir;
	//struct dirent	*file;

	(void)ls;
	(void)av;
	while (i < ac)
	{
		//ft_putendl(av[i]);
		if ((dir = opendir(av[i])) != NULL)
		{

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 01:38:12 by sduprey           #+#    #+#             */
/*   Updated: 2016/11/12 05:19:02 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	open_dir(t_elem *elem)
{
	t_elem			*e;
	DIR				*dir;
	struct dirent	*file;

	e = elem;
	while (e != NULL)
	{
		ft_putstr(e->name);
		ft_putendl(":");
		if ((dir = opendir(e->name)) != NULL)
		{
			while ((file = readdir(dir)) != NULL)
			{
				ft_putnbr(file->d_type);
				ft_putstr(": ");
				ft_putendl(file->d_name);
			}
			closedir(dir);
		}
		else
		{
			if (errno == ENOENT)
			{
				ft_putendl("No exists");
			}
			printf("errno: %d\n", errno);
			ft_putstr("ft_ls: ");
			ft_putstr(e->name);
			perror(": ");
			//ft_putendl(": No such file or directory");
		}
		e = e->next;
		if (e != NULL)
			ft_putchar('\n');
	}
}

int		main(int ac, char **av)
{
	t_ls	ls;
	//t_elem	*e;
	int		i;

	i = get_options(ac, av, &ls);
	get_arguments(ac, av, i, &ls);
	//open_dir(ls.elem, err);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 01:38:12 by sduprey           #+#    #+#             */
/*   Updated: 2016/11/12 05:30:51 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void		print_errors(t_elem *err)
{
	while (err != NULL)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(err->name);
		ft_putendl(": No such file or directory");
		err = err->next;
	}
}

void		print_files(t_elem *file)
{
	while (file != NULL)
	{
		ft_putendl(file->name);
		file = file->next;
	}
}

int		main(int ac, char **av)
{
	t_ls	ls;
	int		i;

	ls.dir = NULL;
	ls.file = NULL;
	ls.err = NULL;
	ft_putendl("get_options");
	i = get_options(ac, av, &ls);
	ft_putendl("get_arguments");
	get_arguments(ac, av, i, &ls);

	ft_putendl("order_elements(ls.err)");
	order_elements(ls.err);
	ft_putendl("order_elements(ls.file)");
	order_elements(ls.file);
	ft_putendl("order_elements(ls.dir)");
	order_elements(ls.dir);
	
	ft_putendl("=== DIRECTORIES ===");
	print_elements(ls.dir);
	ft_putendl("=== FILES ===");
	print_elements(ls.file);
	ft_putendl("=== ERRORS ===");
	print_elements(ls.err);
	ft_putendl("==================");

	print_errors(ls.err);
	print_files(ls.file);

	return (0);
}

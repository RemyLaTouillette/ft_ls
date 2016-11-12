/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 01:46:18 by sduprey           #+#    #+#             */
/*   Updated: 2016/11/12 02:25:46 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	check_arg(char *arg, t_ls *ls)
{
	int	i;

	i = 1;
	while (arg[i] != '\0')
	{
		if (arg[i] == 'l')
			ls->l = 1;
		else if (arg[i] == 'a')
			ls->a = 1;
		else if (arg[i] == 'r')
			ls->r = 1;
		else if (arg[i] == 'R')
			ls->ur = 1;
		else if (arg[i] == 't')
			ls->t = 1;
		else
		{
			ft_putstr("ft_ls: illegal option -- ");
			ft_putchar(arg[i]);
			ft_putchar('\n');
			ft_putendl("usage: ft_ls [-Ralrt] [file ...]");
			exit(0);
		}
		i++;
	}
}

int		get_options(int ac, char **av, t_ls *ls)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-')
			check_arg(av[i], ls);
		else
			break ;
		i++;
	}
	return (i);
}

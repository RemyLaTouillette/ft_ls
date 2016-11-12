/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 02:26:05 by sduprey           #+#    #+#             */
/*   Updated: 2016/11/12 05:18:59 by sduprey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

t_elem	*new_element(char *name)
{
	t_elem	*e;

	e = (t_elem *)malloc(sizeof(t_elem));
	e->name = name;
	e->type = 0;
	e->next = NULL;
	//e->down = NULL;
	return (e);
}

t_elem	*add_element(t_elem *top, char *name)
{
	t_elem	*e;

	e = new_element(name);
	if (top != NULL)
		e->next = top;
	return (e);
}

void	order_elements(t_elem *top)
{
	t_elem	*e;
	int	check;
	char	*tmp;

	if (top == NULL)
		return ;
	check = 1;
	while (check == 1)
	{
		e = top;
		check = 0;
		while (e->next != NULL)
		{
			if (ft_strcmp(e->name, e->next->name) > 0)
			{
				tmp = e->name;
				e->name = e->next->name;
				e->next->name = tmp;
				check = 1;
			}
			e = e->next;
		}
	}
}

void	print_elements(t_elem *top)
{
	int	i;

	i = 0;
	while (top != NULL)
	{
		ft_putnbr(i);
		ft_putstr(": ");
		ft_putendl(top->name);
		top = top->next;
		i++;
	}
}

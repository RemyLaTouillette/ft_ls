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

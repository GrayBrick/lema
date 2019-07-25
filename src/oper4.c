/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 19:05:12 by kmurch            #+#    #+#             */
/*   Updated: 2019/07/25 18:12:09 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

t_cell	*rem(t_cell *cells, int f, char **str)
{
	cells = addmem(cells, *str);
	if (!isvalidstr(*str) || (f && !isroom(*str)))
	{
		free(*str);
		delstruct(cells, 0);
		return ((cells = 0));
	}
	return (cells);
}

t_cell	*rem1(t_cell *cells, int *f, char *str)
{
	cont(*f);
	if (!setcell(str, cells))
	{
		free(str);
		delstruct(cells, 0);
		return ((cells = 0));
	}
	free(str);
	(*f) = 0;
	return (cells);
}

t_cell	*rem2(t_cell *cells, int *f, char **str)
{
	if (ft_strequ(*str, "##start"))
	{
		if (g_gen.s != -1)
		{
			free(*str);
			return (delstruct(cells, 0));
		}
		*f = 1;
	}
	if (ft_strequ(*str, "##end"))
	{
		if (g_gen.e != -1)
		{
			free(*str);
			return (delstruct(cells, 0));
		}
		*f = 2;
	}
	free(*str);
	return (cells);
}

int		phelp(char *str)
{
	if (str[1] != '#' || (!ft_strequ(str, "##start")
				&& !ft_strequ(str, "##end")))
	{
		free(str);
		return (1);
	}
	return (0);
}

t_cell	*rem3(t_cell *cells, int s, char *str)
{
	if (!s && !((g_gen.ants = isant(str, 1))))
	{
		free(str);
		delstruct(cells, 0);
		return ((cells = 0));
	}
	return (cells);
}

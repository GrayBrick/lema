/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 19:05:16 by kmurch            #+#    #+#             */
/*   Updated: 2019/07/25 17:18:38 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

t_cell	*getr(t_cell *cells)
{
	int	x;

	x = -1;
	while (++x <= g_gen.sum)
		cells = getce(cells, x);
	cells[g_gen.e].len = 0;
	dij(cells, g_gen.e);
	return (cells);
}

t_cell	*rem4(t_cell *cells, int *s, char *str)
{
	int x;

	if (isroom(str) && *s == 1)
	{
		if (!setcell(str, cells))
		{
			free(str);
			return (delstruct(cells, 0));
		}
	}
	if ((*s) == 1 && !isroom(str) && ((*s)++))
	{
		if (!g_gen.sum)
		{
			free(str);
			return (delstruct(cells, 0));
		}
		x = -1;
		while (++x <= g_gen.sum && ((g_gen.hear = 1) || 1))
		{
			cells[x].near = (int *)malloc(sizeof(int) * g_gen.sum);
			cells[x].near[0] = 0;
		}
	}
	return (cells);
}

t_cell	*rem5(t_cell *cells, int s, char *str)
{
	int	*ret;

	if (s == 2 && iscon(str))
	{
		if (!(ret = getcell(cells, getar(str, 0, '-'), getar(str, 1, '-'))))
		{
			free(str);
			delstruct(cells, 1);
			return ((cells = 0));
		}
		if (!iinarr(cells[ret[0]].near, ret[1]))
			cells[ret[0]].near[++cells[ret[0]].near[0]] = ret[1];
		if (!iinarr(cells[ret[1]].near, ret[0]))
			cells[ret[1]].near[++cells[ret[1]].near[0]] = ret[0];
		free(ret);
	}
	return (cells);
}

t_ant	*cemr(t_ant *ants, int x, int *m, t_cell *cells)
{
	ants = gant(ants, x, cells);
	while (ants[x].i != g_gen.e)
	{
		(*m) = getm(cells, ants, x, 0);
		ants[x].way[++ants[x].way[0]] = *m;
		ants[x].i = *m;
	}
	ants[x].i = 1;
	return (ants);
}

t_cell	*getce(t_cell *cells, int x)
{
	cells[x].len = -1;
	cells[x].p = 0;
	cells[x].wei = 1;
	cells[x].block = (int *)malloc(sizeof(int) * (cells[x].near[0] + 1));
	cells[x].block[0] = 0;
	return (cells);
}

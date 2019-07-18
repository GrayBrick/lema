/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 18:59:09 by kmurch            #+#    #+#             */
/*   Updated: 2019/07/18 12:57:52 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int		getm(t_cell *cells, t_ant *ants, int x, int f)
{
	int i;
	int m;

	i = 0;
	m = -1;
	while (++i <= cells[ants[x].i].near[0])
	{
		if (f)
		{
			if (iinarr(cells[ants[x].i].block, cells[ants[x].i].near[i]))
				continue ;
			if (iinarr(ants[x].way, cells[ants[x].i].near[i]))
				continue ;
		}
		if (m == -1 && ((m = cells[ants[x].i].near[i]) || 1))
			continue ;
		if (cells[cells[ants[x].i].near[i]].len < cells[m].len && ((m =
						cells[ants[x].i].near[i]) || 1))
			continue ;
		if (cells[cells[ants[x].i].near[i]].len == cells[m].len &&
				cells[cells[ants[x].i].near[i]].near[0]
				< cells[m].near[0])
			m = cells[ants[x].i].near[i];
	}
	return (m);
}

int		*getcell(t_cell *cells, char *s1, char *s2)
{
	int x;
	int *ret;
	int c;

	c = 0;
	ret = (int *)malloc(sizeof(int) * 2);
	x = -1;
	while (++x <= g_gen.sum)
	{
		if (ft_strequ(cells[x].name, s1) && ++c)
			ret[0] = cells[x].i;
		if (ft_strequ(cells[x].name, s2) && ++c)
			ret[1] = cells[x].i;
		if (c == 2)
		{
			ft_strdel(&s1);
			ft_strdel(&s2);
			return (ret);
		}
	}
	ft_strdel(&s1);
	ft_strdel(&s2);
	free(ret);
	return (0);
}

void	copy(t_cell *cells, t_cell *ccell)
{
	int x;

	x = -1;
	while (++x <= g_gen.sum)
	{
		cells[x].i = ccell[x].i;
		cells[x].len = 0;
		cells[x].p = -1;
		cells[x].isant = ccell[x].isant;
		cells[x].name = ft_strdup(ccell[x].name);
	}
}

t_cell	*addmem(t_cell *cells, char *str)
{
	t_cell	*ccell;

	ft_putendl(str);
	if (g_gen.sum + 1 == g_gen.mem)
	{
		ccell = (t_cell *)malloc(sizeof(t_cell) * (g_gen.mem * 2));
		copy(ccell, cells);
		delstruct(cells, 0);
		cells = (t_cell *)malloc(sizeof(t_cell) * (g_gen.mem * 2));
		copy(cells, ccell);
		delstruct(ccell, 0);
		g_gen.mem *= 2;
	}
	return (cells);
}

void	cont(int f)
{
	if (f == 1)
		g_gen.s = g_gen.sum + 1;
	if (f == 2)
		g_gen.e = g_gen.sum + 1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 18:48:41 by kmurch            #+#    #+#             */
/*   Updated: 2019/07/08 18:52:36 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int		iinarr(int *arr, int a)
{
	int x;

	x = 0;
	if (!arr[0])
		return (0);
	while (++x <= arr[0])
		if (arr[x] == a)
			return (1);
	return (0);
}

int		isnear(t_cell *cells, int a, int b)
{
	int x;

	x = 0;
	while (++x <= cells[a].near[0])
		if (cells[cells[a].near[x]].i == cells[b].i)
			return (1);
	return (0);
}

void	change_p(t_cell *cells, int m)
{
	int x;
	int i;
	int b;
	int *list;

	if (m == g_gen.e || (cells[m].isant && m != g_gen.s))
		return ;
	cells[m].len++;
	x = 0;
	list = (int *)malloc(sizeof(int) * (cells[m].near[0] + 1));
	list[0] = 0;
	while (++x <= cells[m].near[0] && ((b = 1) || 1))
	{
		i = 0;
		while (++i <= cells[cells[m].near[x]].near[0])
			if (cells[cells[m].near[x]].len > cells[cells[cells[m].
					near[x]].near[i]].len && ((b = 0) || 1))
				break ;
		if (b)
			list[++list[0]] = cells[m].near[x];
	}
	x = 0;
	while (++x <= list[0])
		change_p(cells, list[x]);
	free(list);
}

void	dij(t_cell *cells, int m)
{
	int x;
	int i;

	if (((x = 0) || 1) && m == -1)
		return ;
	cells[m].p = 1;
	while (++x <= cells[m].near[0])
	{
		if (cells[cells[m].near[x]].p)
			continue;
		if (cells[cells[m].near[x]].len == -1 ||
				cells[cells[m].near[x]].len > cells[m].len + cells[m].wei)
			cells[cells[m].near[x]].len = cells[m].len + cells[m].wei;
	}
	i = -1;
	x = -1;
	while (++x <= g_gen.sum)
		if (!cells[x].p && cells[x].len != -1)
		{
			if (i == -1 && ((i = x) || 1))
				continue ;
			if (cells[x].len < cells[i].len)
				i = x;
		}
	dij(cells, i);
}

t_ant	*gant(t_ant *ants, int x, t_cell *cells)
{
	ants[x].i = g_gen.s;
	ants[x].way = malloc(sizeof(int) * g_gen.sum);
	ants[x].iway = malloc(sizeof(int) * g_gen.sum);
	ants[x].way[0] = 0;
	ants[x].iway[0] = 0;
	ants[x].way[++ants[x].way[0]] = g_gen.s;
	ants[x].iway[++ants[x].iway[0]] = cells[g_gen.s].len;
	return (ants);
}

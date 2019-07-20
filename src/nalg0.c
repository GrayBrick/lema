/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nalg0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:40:07 by kmurch            #+#    #+#             */
/*   Updated: 2019/07/20 21:18:08 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	freeblock(t_cell *cells)
{
	int	x;

	x = -1;
	while (++x <= g_gen.sum)
	{
		free(cells[x].block);
		cells[x].block = 0;
	}
}

void	blockmem(t_cell *cells)
{
	int	x;

	x = -1;
	while (++x <= g_gen.sum)
	{
		cells[x].block = (int *)malloc(sizeof(int) * (cells[x].near[0] + 1));
		cells[x].block[0] = 0;
	}
}

void	predij(t_cell *cells)
{
	int	x;

	x = -1;
	while (++x <= g_gen.sum)
	{
		cells[x].len = -1;
		cells[x].p = 0;
		cells[x].wei = 1;
	}
	cells[g_gen.e].len = 0;
}

int		getnext(t_cell *cells, int cell)
{
	int	i;
	int	m;

	i = 0;
	m = -1;
	while (++i <= cells[cell].near[0])
	{
		if (iinarr(cells[cell].block, cells[cell].near[i]))
			continue ;
		if (m == -1 && ((m = cells[cell].near[i]) || 1))
			continue ;
		if (cells[cells[cell].near[i]].len < cells[m].len && ((m =
						cells[cell].near[i]) || 1))
			continue ;
		if (cells[cells[cell].near[i]].len == cells[m].len &&
				cells[cells[cell].near[i]].near[0]
				< cells[m].near[0])
			m = cells[cell].near[i];
	}
	return (m);
}

int		*minway(t_cell *cells)
{
	int	*way;

	way = (int *)malloc(sizeof(int) * (cells[g_gen.s].len + 3));
	way[0] = 1;
	way[1] = g_gen.s;
	while (!isnear(cells, way[way[0]], g_gen.e))
		way[++way[0]] = getnext(cells, way[way[0]]);
	way[++way[0]] = g_gen.e;
	return (way);
}

void	printway(t_cell *cells, int *way)
{
	int	x;

	x = 0;
	while (++x <= way[0])
	{
		ft_putstr(cells[way[x]].name);
		if (x != way[0])
			ft_putchar(' ');
	}
	ft_putchar('\n');
}

void	printlen(t_cell *cells)
{
	int	x;

	x = -1;
	while (++x <= g_gen.sum)
		printf("%4s %2d\n", cells[x].name, cells[x].len);
}

void	setblock(t_cell *cells, int *way)
{
	int	x;

	x = 0;
	while (++x <= way[0])
	{
		if (x != way[0])
			cells[way[x]].block[++cells[way[x]].block[0]] = way[x + 1];
	}
}

int		addway(t_cell *cells, int **ways, int x)
{
	predij(cells);
	dij(cells, g_gen.e);
	if (cells[g_gen.s].len == -1)
		return (0);
	ways[x] = minway(cells);
	setblock(cells, ways[x]);
	return (1);
}

void	setdir(t_cell *cells, int **ways, int co)
{
	int	x;
	int	i;

	x = -1;
	while (++x < co)
	{
		i = 0;
		while (++i <= ways[x][0])
		{
			if (i != 1)
				cells[ways[x][i]].block[++cells[ways[x][i]].block[0]] = ways[x][i - 1];
		}
		free(ways[x]);
	}
	free(ways);
}

void	go(t_cell *cells)
{
	int	i;
	t_a	*ants;
	int	x;
	int	b;
	int	buf;

	ants = (t_a *)malloc(sizeof(t_a) * (g_gen.ants + 1));
	x = 0;
	while (++x <= g_gen.ants)
	{
		ants[x].now = g_gen.s;
		ants[x].be = -1;
	}
	i = 0;
	while (i != g_gen.ants)
	{
		x = 0;
		b = 0;
		while (++x <= g_gen.ants)
		{
			if (ants[x].now == g_gen.e)
				continue ;
			if (ants[x].be == -1)
			{
				buf = getnext(cells, ants[x].now);
				if (cells[buf].len >= cells[ants[x].now].len)
					continue ;
				ants[x].be = buf;
				cells[ants[x].now].len++;
				cells[ants[x].be].len++;
				b = 1;
				continue ;
			}
			if (!cells[ants[x].be].isant || ants[x].be == g_gen.e)
			{
				b = 1;
				if (ants[x].be != g_gen.e)
					cells[ants[x].be].isant = 1;
				if (ants[x].now != g_gen.s)
					cells[ants[x].now].isant = 0;
				ants[x].now = ants[x].be;
				ants[x].be = getnext(cells, ants[x].now);
				printf("L%d-%s ", x, cells[ants[x].now].name);
				if (ants[x].now == g_gen.e)
					i++;
			}
		}
		if (b == 1)
			printf("  %d/%d\n", i, g_gen.ants);
	}
}

void	start(t_cell *cells)
{
	int	**ways;
	int	x;

	blockmem(cells);
	ways = (int **)malloc(sizeof(int *) * cells[g_gen.s].near[0]);
	x = 0;
	while (addway(cells, ways, x))
		x++;
	freeblock(cells);
	blockmem(cells);
	setdir(cells, ways, x);
	predij(cells);
	dij(cells, g_gen.e);
	x = 0;
	while (++x <= cells[g_gen.s].near[0])
	{
		if (cells[x].len > cells[g_gen.s].len)
			cells[g_gen.s].block[++cells[g_gen.s].block[0]] = cells[g_gen.s].near[x];
	}
	go(cells);
	freeblock(cells);
}

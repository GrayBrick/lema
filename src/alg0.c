/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg0.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 10:27:39 by kmurch            #+#    #+#             */
/*   Updated: 2019/07/18 18:12:16 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

t_ant	*cem2(t_cell *cells, t_ant *ants, int x, int *m)
{
	while ((*m) > 0)
	{
		if (cells[ants[x].way[(*m)]].len == ants[x].iway[(*m)])
			change_p(cells, ants[x].way[(*m)]);
		if ((*m) != 1 && !iinarr(cells[ants[x].way[(*m)]].block,
					ants[x].way[(*m) - 1]))
			cells[ants[x].way[(*m)]].block[++cells[ants[x].way[(*m)]]
				.block[0]] = ants[x].way[(*m) - 1];
		(*m)--;
	}
	ants[x].i = 1;
	return (ants);
}

t_ant	*cem1(t_ant *ants, int x, int *m, t_cell *cells)
{
	ants = gant(ants, x, cells);
	while (ants[x].i != g_gen.e)
	{
		(*m) = getm(cells, ants, x, 1);
		if (*m == -1)
		{
			x = 0;
			while (++x <= g_gen.ants)
			{
				free(ants[x].way);
				free(ants[x].iway);
			}
			free(ants);
			ants = 0;
			return (ants);
		}
		ants[x].way[++ants[x].way[0]] = *m;
		ants[x].iway[++ants[x].iway[0]] = cells[*m].len;
		ants[x].i = *m;
	}
	(*m) = ants[x].way[0];
	return (cem2(cells, ants, x, m));
}

t_ant	*cem(t_cell *cells, t_ant *ants)
{
	int x;
	int	m;

	cells = getr(cells);
	if (cells[g_gen.s].len == -1 && (((x = -1) || 1)))
	{
		while (++x <= g_gen.sum)
			free(cells[x].block);
		free(ants);
		return ((ants = 0));
	}
	x = 0;
	while (++x <= g_gen.ants)
		if (!(ants = cem1(ants, x, &m, cells)))
		{
			x = 0;
			ants = (t_ant *)malloc(sizeof(t_ant) * (g_gen.ants + 1));
			while (++x <= g_gen.ants)
				ants = cemr(ants, x, &m, cells);
			break ;
		}
	x = -1;
	while (++x <= g_gen.sum)
		free(cells[x].block);
	return (ants);
}

int		print(t_cell *cells, t_ant *ants, int *i, int x)
{
	int	m;

	if (isnear(cells, ants[x].way[ants[x].i], g_gen.e))
	{
		if (g_gen.x++ != 0)
			ft_putchar(' ');
		printant(x, cells[g_gen.e].name);
		cells[ants[x].way[ants[x].i]].isant = 0;
		ants[x].i = -1;
		free(ants[x].way);
		free(ants[x].iway);
		return ((*i)++);
	}
	m = ants[x].way[ants[x].i + 1];
	if (!cells[m].isant)
	{
		if (g_gen.x++ != 0)
			ft_putchar(' ');
		printant(x, cells[m].name);
		cells[ants[x].way[ants[x].i]].isant = 0;
		cells[m].isant = 1;
		return (ants[x].i++);
	}
	return (0);
}

void	alga(t_cell *cells)
{
	int		x;
	int		i;
	t_ant	*ants;

	ants = (t_ant *)malloc(sizeof(t_ant) * (g_gen.ants + 1));
	if (!(ants = cem(cells, ants)))
	{
		ft_putendl("ERROR");
		exit(1);
	}
	i = 0;
	while (i != g_gen.ants)
	{
		x = 0;
		g_gen.x = 0;
		while (++x <= g_gen.ants)
		{
			if (ants[x].i != -1)
				print(cells, ants, &i, x);
		}
		ft_putchar('\n');
	}
	free(ants);
}

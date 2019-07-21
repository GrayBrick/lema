/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 16:39:58 by kmurch            #+#    #+#             */
/*   Updated: 2019/07/21 14:22:35 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	main(void)
{
	t_cell	*cells;

	g_gen.sum = -1;
	g_gen.mem = 2;
	g_gen.s = -1;
	g_gen.e = -1;
	cells = NULL;
	if (!(cells = getstr(cells)))
	{
		ft_putendl("ERROR");
		exit(1);
	}
	if (g_gen.s == -1 || g_gen.e == -1)
	{
		ft_putendl("ERROR");
		exit(1);
	}
	cells[g_gen.e].isant = -1;
	cells[g_gen.s].isant = -1;
	ft_putchar('\n');
	alga(cells);
	delstruct(cells, 2);
	exit(1);
}

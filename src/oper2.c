/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 18:37:25 by kmurch            #+#    #+#             */
/*   Updated: 2019/07/13 17:36:13 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int		setcell(char *str, t_cell *cells)
{
	int		x;
	char	*s;

	x = -1;
	s = getar(str, 0, ' ');
	while (++x <= g_gen.sum)
	{
		if (ft_strequ(cells[x].name, s))
			return (ft_strdel(&s));
	}
	cells[++g_gen.sum].name = s;
	cells[g_gen.sum].near = NULL;
	cells[g_gen.sum].isant = 0;
	cells[g_gen.sum].p = -1;
	cells[g_gen.sum].len = 0;
	cells[g_gen.sum].i = g_gen.sum;
	return (1);
}

int		dellist(char **str)
{
	int	x;

	x = -1;
	while (str[++x])
		ft_strdel(&str[x]);
	free(str);
	return (0);
}

int		isant(char *str, int i)
{
	char	*ant;

	ant = ft_itoa(ft_atoi(str));
	if (!ft_strequ(str, ant) || (i && ft_atoi(str) <= 0))
	{
		ft_strdel(&ant);
		return (0);
	}
	ft_strdel(&ant);
	if (i == 1)
		return (ft_atoi(str));
	return (1);
}

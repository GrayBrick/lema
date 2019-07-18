/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 12:31:34 by kmurch            #+#    #+#             */
/*   Updated: 2019/07/16 18:12:35 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

t_cell		*delstruct(t_cell *cell, int f)
{
	int		x;

	x = -1;
	while (++x <= g_gen.sum)
	{
		ft_strdel(&(cell[x].name));
		if (f)
			free(cell[x].near);
	}
	free(cell);
	return ((cell = 0));
}

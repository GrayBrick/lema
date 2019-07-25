/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 19:49:07 by kmurch            #+#    #+#             */
/*   Updated: 2019/07/25 17:52:18 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int			phelp1(int *s, char *str)
{
	if (!(*s) && (++(*s)))
	{
		free(str);
		return (1);
	}
	return (0);
}

t_cell		*rem6(t_cell *cells, int *s, char *str)
{
	if (!(cells = rem4(cells, s, str)) ||
			!(cells = rem5(cells, *s, str)))
		return (cells);
	free(str);
	return (cells);
}

t_cell		*rem7(t_cell *cells, int *f, int *s, char *str)
{
	if (!(cells = rem(cells, *f, &str)))
		return ((cells = 0));
	if (f && isroom(str))
	{
		if (!(cells = rem1(cells, f, str)))
			return ((cells = 0));
		return (cells);
	}
	if (str[0] == '#')
	{
		if (phelp(str))
			return (cells);
		if (!(cells = rem2(cells, f, &str)))
			return (cells);
		return (cells);
	}
	if (!(cells = rem3(cells, *s, str)))
		return (cells);
	else if (phelp1(s, str))
		return (cells);
	if (!(cells = rem6(cells, s, str)))
		return (cells);
	return (cells);
}

t_cell		*getstr(t_cell *cells)
{
	char	*str;
	int		s;
	int		f;
	int		x;

	f = 0;
	s = 0;
	x = 0;
	str = NULL;
	while (get_next_line(0, &str) > 0 && ((str = cpytmp(&str)) || 1))
	{
		if (x == 0 && ft_strequ(str, ""))
			return (clearww(str, cells));
		if (!x++)
		{
			cells = (t_cell *)malloc(sizeof(t_cell) * 2);
			setcell("L1 0 0", cells);
			g_gen.sum = 0;
		}
		if (!(cells = rem7(cells, &f, &s, str)))
			return ((cells = 0));
	}
	if (!x || s < 2)
		return (delstruct(cells, 0));
	return (cells);
}

char		*getar(char *str, int i, char c)
{
	char	**ret;
	char	*name;

	ret = ft_strsplit(str, c);
	name = ft_strdup(ret[i]);
	dellist(ret);
	return (name);
}

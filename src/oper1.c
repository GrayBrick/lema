/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:18:13 by kmurch            #+#    #+#             */
/*   Updated: 2019/07/25 17:34:58 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int		isroom(char *str)
{
	char	**ret;
	int		i;

	ret = ft_strsplit(str, ' ');
	i = -1;
	while (ret[++i])
		;
	if ((i != 3 || str[0] == '#') || (!isant(ret[1], 0) || !isant(ret[2], 0)))
		return (dellist(ret));
	dellist(ret);
	return (1);
}

int		iscon(char *str)
{
	int		x;
	int		m;
	char	**ret;

	x = -1;
	ret = ft_strsplit(str, ' ');
	while (ret[++x])
		;
	dellist(ret);
	if (x != 1)
		return (0);
	ret = ft_strsplit(str, '-');
	x = -1;
	while (ret[++x])
		;
	if (x != 2)
		return (dellist(ret));
	dellist(ret);
	x = -1;
	m = 0;
	while (str[++x])
		if (str[x] == '-' && ((m++) || 1))
			if (m > 1)
				return (0);
	return (1);
}

char	*cpytmp(char **str)
{
	char	*tmp;

	tmp = ft_strdup(*str);
	free(*str);
	return (tmp);
}

void	printant(int x, char *name)
{
	ft_putchar('L');
	ft_putnbr(x);
	ft_putchar('-');
	ft_putstr(name);
}

int		isvalidstr(char *str)
{
	if (!str || ft_strequ(str, ""))
		return (0);
	if (str[0] && str[0] == '#')
		return (1);
	if (isroom(str) || isant(str, 1) || iscon(str))
		return (1);
	return (0);
}

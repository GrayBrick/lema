/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 11:53:22 by kmurch            #+#    #+#             */
/*   Updated: 2019/02/22 16:05:47 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_strcadd(char **str, char c)
{
	char	*ret;
	int		x;

	if (!(ret = ft_strnew(ft_strlen(*str) + 1)))
		return ;
	ret[0] = c;
	x = -1;
	while ((*str)[++x])
		ret[x + 1] = (*str)[x];
	ft_strdel(str);
	*str = ret;
}

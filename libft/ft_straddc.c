/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:14:33 by kmurch            #+#    #+#             */
/*   Updated: 2019/02/22 16:05:49 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_straddc(char **ret, char c)
{
	char	*str;
	int		x;

	if (!(str = ft_strnew(ft_strlen(*ret) + 1)))
		return ;
	x = -1;
	while ((*ret)[++x])
		str[x] = (*ret)[x];
	str[x] = c;
	str[++x] = '\0';
	ft_strdel(ret);
	*ret = str;
}

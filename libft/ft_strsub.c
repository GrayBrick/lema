/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 07:26:14 by kmurch            #+#    #+#             */
/*   Updated: 2019/02/19 20:18:46 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	int		x;

	if (!(ret = ft_strnew(len)))
		return (0);
	x = 0;
	while (x < (int)len)
	{
		if (s[start])
			ret[x] = s[start];
		x++;
		start++;
	}
	return (ret);
}

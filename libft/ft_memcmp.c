/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:08:15 by kmurch            #+#    #+#             */
/*   Updated: 2018/11/26 20:47:27 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *memptr1, const void *memptr2, size_t num)
{
	unsigned char	*buf;
	unsigned char	*buf1;
	size_t			x;

	x = -1;
	buf = (unsigned char *)memptr1;
	buf1 = (unsigned char *)memptr2;
	while (++x < num)
	{
		if (*(buf + x) != *(buf1 + x))
			return (*(buf + x) - *(buf1 + x));
	}
	return (0);
}

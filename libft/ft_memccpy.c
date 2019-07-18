/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:26:06 by kmurch            #+#    #+#             */
/*   Updated: 2018/11/23 14:43:20 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destptr, const void *srcptr, int ch, size_t num)
{
	char	*buf;
	size_t	x;

	buf = destptr;
	x = -1;
	while (++x < num)
	{
		*(buf + x) = *((unsigned char *)srcptr + x);
		if (*((unsigned char *)srcptr + x) == (unsigned char)ch)
			return (destptr + x + 1);
	}
	return (NULL);
}

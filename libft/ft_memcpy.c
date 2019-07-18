/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:08:07 by kmurch            #+#    #+#             */
/*   Updated: 2018/11/26 20:42:24 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destptr, const void *srcptr, size_t num)
{
	char	*buf;
	char	*buf1;
	size_t	x;

	buf = destptr;
	buf1 = (char *)srcptr;
	x = -1;
	while (++x < num)
		*(buf + x) = *(buf1 + x);
	return (destptr);
}

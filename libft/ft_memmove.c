/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:15:41 by kmurch            #+#    #+#             */
/*   Updated: 2018/11/26 20:44:03 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destptr, const void *srcptr, size_t num)
{
	char	*buf;
	char	*buf1;
	size_t	x;

	buf = (char *)destptr;
	buf1 = (char *)srcptr;
	x = -1;
	if (buf1 < buf)
	{
		while ((int)(--num) >= 0)
			*(buf + num) = *(buf1 + num);
	}
	else
	{
		while (++x < num)
			*(buf + x) = *(buf1 + x);
	}
	return (destptr);
}

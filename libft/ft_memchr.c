/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:48:45 by kmurch            #+#    #+#             */
/*   Updated: 2018/11/26 20:46:30 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *obj, int ch, size_t num)
{
	const char	*buf;
	size_t		x;

	x = -1;
	buf = (const char *)obj;
	while (++x < num)
	{
		if (*(buf + x) == (char)ch)
		{
			return ((void *)obj + x);
		}
	}
	return (NULL);
}

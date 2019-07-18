/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:29:57 by kmurch            #+#    #+#             */
/*   Updated: 2018/11/26 20:56:05 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s_dst;
	size_t	s_src;
	size_t	sd;
	int		x;

	x = 0;
	sd = ft_strlen(dst);
	s_dst = ft_strlen(dst);
	s_src = ft_strlen(src);
	if (s_dst + 1 > size)
		return (s_src + size);
	if (s_dst + 1 < size)
	{
		while (sd < size - 1)
			*(dst + sd++) = *(src + x++);
		dst[sd] = '\0';
	}
	return (s_dst + s_src);
}

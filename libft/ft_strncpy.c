/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:05:59 by kmurch            #+#    #+#             */
/*   Updated: 2018/11/26 20:50:52 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t num)
{
	size_t	x;

	x = -1;
	while (++x < num)
	{
		if (src[x])
			dest[x] = src[x];
		else
			while (x < num)
				dest[x++] = '\0';
	}
	return (dest);
}

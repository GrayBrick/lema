/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:05:15 by kmurch            #+#    #+#             */
/*   Updated: 2019/02/17 18:08:06 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *destptr, const char *srcptr)
{
	int		x;

	x = -1;
	while (srcptr[++x])
		destptr[x] = srcptr[x];
	destptr[x] = '\0';
	return (destptr);
}

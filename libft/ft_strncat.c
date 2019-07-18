/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:16:09 by kmurch            #+#    #+#             */
/*   Updated: 2018/11/23 17:25:32 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *destptr, char *srcptr, size_t num)
{
	int		x;
	int		i;

	i = -1;
	x = (int)ft_strlen(destptr);
	while (srcptr[++i] && i < (int)num)
		destptr[x + i] = srcptr[i];
	destptr[x + i] = '\0';
	return (destptr);
}

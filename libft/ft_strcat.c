/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:44:17 by kmurch            #+#    #+#             */
/*   Updated: 2018/11/23 18:53:29 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *destptr, char *srcptr)
{
	int		x;
	int		i;

	i = -1;
	x = (int)ft_strlen(destptr);
	while (srcptr[++i])
		destptr[x + i] = srcptr[i];
	destptr[x + i] = '\0';
	return (destptr);
}

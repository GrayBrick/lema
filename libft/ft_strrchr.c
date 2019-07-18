/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:58:41 by kmurch            #+#    #+#             */
/*   Updated: 2018/11/26 21:02:39 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int symbol)
{
	int		x;

	x = 1 + (int)ft_strlen(string);
	while (x--)
	{
		if (string[x] == symbol)
			return ((char *)string + x);
	}
	return (NULL);
}

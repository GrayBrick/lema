/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:50:04 by kmurch            #+#    #+#             */
/*   Updated: 2018/12/15 20:17:12 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int symbol)
{
	int		x;

	x = -1;
	while (++x < (int)ft_strlen(string) + 1)
	{
		if (string[x] == (char)symbol)
			return ((char *)string + x);
	}
	return (0);
}

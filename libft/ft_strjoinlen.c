/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 11:53:14 by kmurch            #+#    #+#             */
/*   Updated: 2019/02/24 11:55:28 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinlen(char const *s1, int size1, char const *s2, int size2)
{
	char	*ret;
	int		x;
	int		i;

	if (!s1 || !s2)
		return (0);
	x = -1;
	i = -1;
	ret = ft_strnew(size1 + size2);
	if (!ret)
		return (0);
	while (++x < size1)
		ret[x] = s1[x];
	while (++i < size2)
		ret[x++] = s2[i];
	return (ret);
}

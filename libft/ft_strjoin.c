/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 07:33:15 by kmurch            #+#    #+#             */
/*   Updated: 2019/02/17 16:35:04 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size1;
	int		size2;
	char	*ret;
	int		x;
	int		i;

	if (!s1 || !s2)
		return (0);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
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

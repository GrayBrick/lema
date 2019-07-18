/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 00:07:22 by kmurch            #+#    #+#             */
/*   Updated: 2018/11/28 16:11:13 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strnlen(const char *s, size_t n)
{
	int		x;

	x = 0;
	while (s[x] && x < (int)n - 1)
		x++;
	return (x);
}

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	ns1;
	size_t	ns2;
	int		ret;

	ns1 = ft_strnlen(s1, n) + 1;
	ns2 = ft_strnlen(s2, n) + 1;
	ret = 0;
	n = ns1 < n ? ns1 : n;
	n = ns2 < n ? ns2 : n;
	while (n && (ret = *(unsigned char *)s1++ - *(unsigned char *)s2++) == 0)
		n--;
	return (ret);
}

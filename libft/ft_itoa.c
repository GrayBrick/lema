/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:18:22 by kmurch            #+#    #+#             */
/*   Updated: 2019/02/23 12:49:32 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long long int	ft_sizechar(long long int n)
{
	unsigned long long int		x;

	x = 1;
	while (n /= 10)
		x++;
	return (x);
}

char							*ft_itoa(long long int n)
{
	unsigned long long int	f;
	size_t					x;
	char					*ret;

	x = ft_sizechar(n);
	f = n;
	if (n < 0)
	{
		f = -n;
		x++;
	}
	if (!(ret = ft_strnew(x)))
		return (NULL);
	ret[--x] = f % 10 + '0';
	while (f /= 10)
		ret[--x] = f % 10 + '0';
	if (n < 0)
		ret[0] = '-';
	return (ret);
}

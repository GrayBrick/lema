/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strojoinlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 11:56:06 by kmurch            #+#    #+#             */
/*   Updated: 2019/02/24 19:35:47 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strojoinlen(char **s1, int size1, char const *s2, int size2)
{
	char	*ret;

	if (!(ret = ft_strjoinlen(*s1, size1, s2, size2)))
		return (0);
	ft_strdel(s1);
	*s1 = ret;
	return (1);
}

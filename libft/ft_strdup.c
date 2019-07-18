/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:29:23 by kmurch            #+#    #+#             */
/*   Updated: 2018/11/23 16:37:34 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*buf;

	if (!(buf = ft_strnew(ft_strlen(src))))
		return (NULL);
	ft_strcpy(buf, src);
	return (buf);
}

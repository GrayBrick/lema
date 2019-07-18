/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memoset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 12:23:29 by kmurch            #+#    #+#             */
/*   Updated: 2019/02/22 13:30:53 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memoset(char **obj, int ch, size_t num)
{
	if (*obj)
		ft_strdel(obj);
	*obj = ft_strnew(0);
	*obj = ft_memset(*obj, ch, num);
}

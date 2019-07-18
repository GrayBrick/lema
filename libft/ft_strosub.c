/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strosub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:18:22 by kmurch            #+#    #+#             */
/*   Updated: 2019/02/20 17:37:34 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strosub(char **str, int x, int i)
{
	char	*ret;

	if (!(ret = ft_strsub(*str, x, i)))
		return (0);
	ft_strdel(str);
	*str = ret;
	return (1);
}

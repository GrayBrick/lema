/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:37:33 by kmurch            #+#    #+#             */
/*   Updated: 2018/12/19 20:38:21 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_cpy(char **s)
{
	char	**ret;
	int		x;

	x = ft_strlen(s[0]);
	MALLCHECK((ret = (char **)malloc(sizeof(char *) * (x + 1))));
	x = -1;
	while (s[++x])
		MALLCHECK((ret[x] = ft_strdup(s[x])));
	ret[x] = 0;
	return (ret);
}

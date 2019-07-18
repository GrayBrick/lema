/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 09:01:36 by kmurch            #+#    #+#             */
/*   Updated: 2019/05/14 19:54:05 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		cont_words(const char *s, char c)
{
	int		cnt;
	int		flag;

	flag = 0;
	cnt = 0;
	while (*s)
	{
		if (flag == 1 && *s == c)
			flag = 0;
		if (flag == 0 && *s != c)
		{
			flag = 1;
			cnt++;
		}
		s++;
	}
	return (cnt);
}

static int		count_letter(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		words;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	words = cont_words(s, c);
	arr = (char **)malloc(sizeof(char *) * (cont_words(s, c) + 1));
	if (arr == NULL)
		return (NULL);
	while (words--)
	{
		while (*s == c && *s)
			s++;
		arr[i] = ft_strsub(s, 0, count_letter(s, c));
		if (arr[i] == NULL)
			return (NULL);
		s = s + count_letter(s, c);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

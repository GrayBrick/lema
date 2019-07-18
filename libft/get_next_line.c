/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 04:00:21 by kmurch            #+#    #+#             */
/*   Updated: 2019/02/17 16:36:37 by kmurch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_line(char **s, char **line, int fd, int ret)
{
	char	*str;
	int		x;

	x = 0;
	while (s[fd][x] != '\n' && s[fd][x])
		x++;
	if (s[fd][x] == '\n')
	{
		*line = ft_strsub(s[fd], 0, x);
		str = ft_strdup(s[fd] + x + 1);
		free(s[fd]);
		s[fd] = str;
		if (!s[fd][0])
			ft_strdel(&s[fd]);
	}
	else if (!s[fd][x])
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*s[256];
	char		buf[BUFF_SIZE + 1];
	char		*str;
	int			ret;

	if (fd < 0 || !line)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		str = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = str;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (ft_get_line(s, line, fd, ret));
}

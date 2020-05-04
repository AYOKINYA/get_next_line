/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkang <jkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:19:04 by jkang             #+#    #+#             */
/*   Updated: 2020/04/15 10:42:18 by jkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int				ft_free_and_ret(char **s_res, int ret)
{
	if (*s_res)
	{
		free(*s_res);
		*s_res = 0;
	}
	return (ret);
}

int				ft_has_new_line(char *buf, char **s_res, char **line)
{
	int		i;
	char	tmp[BUFFER_SIZE + 1];

	if (ft_strchr(buf, '\n') != 0)
	{
		i = 0;
		while (buf[i] != '\n')
		{
			tmp[i] = buf[i];
			++i;
		}
		tmp[i] = '\0';
		if (!(*line = ft_strjoin(*line, tmp)))
			return (ft_free_and_ret(s_res, -1));
		free(*s_res);
		*s_res = 0;
		if (!(*s_res = ft_strdup(&buf[i + 1])))
			return (ft_free_and_ret(s_res, -1));
		return (1);
	}
	return (0);
}

int				ft_read_s_res(char **s_res, char **line)
{
	int		i;
	char	tmp[BUFFER_SIZE + 1];

	if ((ft_strchr(*s_res, '\n')) == 0)
	{
		if (!(*line = ft_strjoin(*line, *s_res)))
			return (ft_free_and_ret(s_res, -1));
		free(*s_res);
		*s_res = 0;
	}
	else
	{
		i = 0;
		while ((*s_res)[i] != '\n' && (*s_res)[i] != '\0')
		{
			tmp[i] = (*s_res)[i];
			++i;
		}
		tmp[i] = '\0';
		if (!(*line = ft_strjoin(*line, tmp)))
			return (ft_free_and_ret(s_res, -1));
		ft_memmove(*s_res, *s_res + i + 1, ft_strlen(*s_res) - i);
		return (1);
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*s_res[4096];
	size_t			ret;

	if (fd < 0 || line == 0 || (read(fd, buf, 0) < 0) || BUFFER_SIZE < 1)
		return (-1);
	if (!(*line = ft_strdup("")))
		return (ft_free_and_ret(&s_res[fd], -1));
	if (s_res[fd])
	{
		if (ft_read_s_res(&s_res[fd], line) == 1)
			return (1);
	}
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (ft_has_new_line(buf, &s_res[fd], line) == 1)
			return (1);
		if (!(*line = ft_strjoin(*line, buf)))
			return (ft_free_and_ret(&s_res[fd], -1));
	}
	return (ft_free_and_ret(&s_res[fd], ret));
}

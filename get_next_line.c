/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkang <jkang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:19:04 by jkang             #+#    #+#             */
/*   Updated: 2020/07/31 10:24:39 by jkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int		free_and_return(char **s_res, int ret)
{
	if (*s_res)
	{
		free(*s_res);
		*s_res = 0;
	}
	return (ret);
}

static int		read_s_res(char **s_res, char **line)
{
	char	*str;
	char	*piece;
	char	*temp;

	if ((str = ft_strchr(*s_res, '\n')) != 0)
	{
		if (!(piece = ft_substr(*s_res, 0, str - *s_res)))
			return (-1);
		if (!(*line = ft_strjoin(*line, piece)))
		{
			free(piece);
			return (-1);
		}
		free(piece);
		temp = *s_res;
		if (!(*s_res = ft_strdup(str + 1)))
			return (-1);
		free(temp);
		return (1);
	}
	if (!(*line = ft_strjoin(*line, *s_res)))
		return (-1);
	free(*s_res);
	*s_res = 0;
	return (0);
}

static int		read_buf(char **s_res, char **line, char *buf)
{
	char			*piece;
	char			*str;

	if ((str = ft_strchr(buf, '\n')) != 0)
	{
		if (!(piece = ft_substr(buf, 0, str - buf)))
			return (-1);
		if (!(*line = ft_strjoin(*line, piece)))
		{
			free(piece);
			return (-1);
		}
		free(piece);
		if (!(*s_res = ft_strdup(str + 1)))
			return (-1);
		return (1);
	}
	else
	{
		if (!(*line = ft_strjoin(*line, buf)))
			return (-1);
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*s_res;
	int				ret;
	int				check;

	if (fd < 0 || line == 0 || (read(fd, buf, 0) < 0) || BUFFER_SIZE < 1)
		return (-1);
	if (!(*line = ft_strdup("")))
		return (free_and_return(&s_res, -1));
	if (s_res)
	{
		if ((check = read_s_res(&s_res, line)) == 1)
			return (1);
		else if (check == -1)
			return (free_and_return(&s_res, -1));
	}
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((check = read_buf(&s_res, line, buf)) == 1)
			return (1);
		else if (check == -1)
			return (free_and_return(&s_res, -1));
	}
	return (free_and_return(&s_res, ret));
}

// int				main(void)
// {
// 	char *line;

// 	line = 0;
// 	while (get_next_line(0, &line) > 0)
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 	}
// 	printf("%s\n", line);
// 	free(line);
// 	return (0);
// }

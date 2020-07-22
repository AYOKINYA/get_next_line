/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkang <jkang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:16:37 by jkang             #+#    #+#             */
/*   Updated: 2020/07/22 21:40:49 by jkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_strlen(char *s)
{
	int count;

	count = 0;
	while (s[count] != '\0')
		++count;
	return (count);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*joined_str;
	char	*s1_head;
	int		i;

	joined_str = (char *)malloc(sizeof(char) * \
							(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (joined_str == 0)
	{
		free(s1);
		return (0);
	}
	s1_head = s1;
	i = 0;
	while (*s1 != '\0')
		joined_str[i++] = *s1++;
	while (*s2 != '\0')
		joined_str[i++] = *s2++;
	joined_str[i] = '\0';
	free(s1_head);
	return (joined_str);
}

char		*ft_strchr(char *s, int c)
{
	if (s == 0)
		return (0);
	while (*s != c)
	{
		if (*s == '\0')
			return (0);
		++s;
	}
	return (s);
}

char		*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*temp;

	len = 0;
	while (s[len] != '\0')
		++len;
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (temp == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		temp[i] = s[i];
		++i;
	}
	temp[i] = '\0';
	return (temp);
}

char		*ft_substr(char *str, unsigned start, int len)
{
	char	*ptr;
	int		idx;

	idx = 0;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	while (idx < len)
		ptr[idx++] = str[start++];
	ptr[idx] = '\0';
	return (ptr);
}

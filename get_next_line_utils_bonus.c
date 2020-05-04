/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkang <jkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:16:37 by jkang             #+#    #+#             */
/*   Updated: 2020/04/15 10:03:46 by jkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int			ft_strlen(const char *s)
{
	int count;

	count = 0;
	while (s[count] != '\0')
		++count;
	return (count);
}

char		*ft_strjoin(char *s1, char const *s2)
{
	char	*joined_str;
	int		i;
	int		j;

	if (s1 == 0 || s2 == 0)
		return (0);
	joined_str = (char *)malloc(sizeof(char) * \
							(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (joined_str == 0)
		return (0);
	i = -1;
	while (++i < ft_strlen((s1)))
		joined_str[i] = s1[i];
	j = -1;
	while (++j < ft_strlen(s2))
		joined_str[i++] = s2[j];
	joined_str[i] = '\0';
	free(s1);
	return (joined_str);
}

char		*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		++s;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
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

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			n;
	unsigned char	*dest;
	unsigned char	*source;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	n = len;
	if (src <= dst)
	{
		while (n--)
			(*(dest + n) = *(source + n));
	}
	else
	{
		while (len--)
			*(dest++) = *(source++);
	}
	return (dst);
}

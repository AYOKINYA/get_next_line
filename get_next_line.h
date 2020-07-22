/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkang <jkang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 09:19:39 by jkang             #+#    #+#             */
/*   Updated: 2020/07/22 16:23:16 by jkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
#  endif
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

/*
**  get_next_line_utils.c
*/
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_substr(char *str, unsigned start, int len);
/*
**  get_next_line.c
*/
int		get_next_line(int fd, char **line);

#endif

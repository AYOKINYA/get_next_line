/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkang <jkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 09:19:39 by jkang             #+#    #+#             */
/*   Updated: 2020/04/15 09:35:46 by jkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
# endif
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

/*
**  get_next_line_utils.c
*/
int		ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void	*ft_memmove(void *dst, const void *src, size_t len);
/*
**  get_next_line.c
*/
int		ft_free_and_ret(char **s_res, int ret);
int		ft_has_new_line(char *buf, char **s_res, char **line);
int		ft_read_s_res(char **s_res, char **line);
int		get_next_line(int fd, char **line);

#endif

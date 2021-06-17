/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tekim <tekim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:06:48 by tekim             #+#    #+#             */
/*   Updated: 2021/06/01 18:15:43 by tekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

size_t			ft_strlen(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
int				get_next_line(int fd, char **line);
void			*ft_memmove(void *dest, const void *src, size_t num);
char			*ft_front(char *backup);
char			*ft_back(char *backup);
char			*ft_strchr(const char *str, int c);
char			*ft_strdup(const char *s1);

#endif

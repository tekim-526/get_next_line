/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tekim <tekim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:53:59 by tekim             #+#    #+#             */
/*   Updated: 2021/06/01 17:14:19 by tekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t			ft_strlen(const char *s)
{
	int			i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void			*ft_memmove(void *dest, const void *src, size_t num)
{
	size_t		i;
	const char	*s;
	char		*d;

	if (src == NULL && dest == NULL)
		return (NULL);
	s = src;
	d = dest;
	i = 0;
	if (dest > src)
	{
		while (num)
		{
			if (num < 1)
				break ;
			*(d + num - 1) = *(s + num - 1);
			num--;
		}
	}
	while (i < num)
	{
		*(d + i) = *(s + i);
		i++;
	}
	return (dest);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len1;
	size_t		len2;
	char		*ret;

	if (!s1 && !s2)
		return (0);
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	ret = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!ret)
		return (0);
	ft_memmove(ret, s1, len1);
	ft_memmove(ret + len1, s2, len2);
	ret[len1 + len2] = '\0';
	return (ret);
}

char			*ft_strdup(const char *s1)
{
	char		*tmp;
	char		*ret;
	int			i;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (0);
	tmp = ret;
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = 0;
	return (ret);
}

char			*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == c)
		{
			return ((char*)str);
		}
		str++;
	}
	if (c == 0)
		return ((char *)str);
	return (0);
}

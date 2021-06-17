/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tekim <tekim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:12:38 by tekim             #+#    #+#             */
/*   Updated: 2021/06/01 18:14:07 by tekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char				*ft_backup(char *buf, char *backup)
{
	char			*tmp;

	if (backup)
	{
		tmp = ft_strjoin(backup, buf);
		free(backup);
		backup = ft_strdup(tmp);
		free(tmp);
	}
	else
		backup = ft_strdup(buf);
	return (backup);
}

char				*ft_back(char *backup)
{
	char			*ret;
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (!backup)
		return (0);
	while (backup[i] && backup[i] != '\n')
		i++;
	if (!backup[i])
	{
		free(backup);
		return (0);
	}
	if (!(ret = malloc(sizeof(char) * ((ft_strlen(backup) - i) + 1))))
		return (0);
	i++;
	while (backup[i])
		ret[j++] = backup[i++];
	ret[j] = '\0';
	free(backup);
	return (ret);
}

char				*ft_front(char *backup)
{
	int				i;
	char			*ret;

	i = 0;
	if (!backup)
		return (0);
	while (backup[i] && backup[i] != '\n')
		i++;
	if (!(ret = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (backup[i] && backup[i] != '\n')
	{
		ret[i] = backup[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int					get_next_line(int fd, char **line)
{
	static char		*backup[10240];
	char			buf[BUFFER_SIZE + 1];
	int				ret;

	if (BUFFER_SIZE <= 0 || fd < 0 || !line)
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		backup[fd] = ft_backup(buf, backup[fd]);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret <= 0 && !backup[fd])
		*line = ft_strdup("");
	else
		*line = ft_front(backup[fd]);
	if (!(backup[fd] = ft_back(backup[fd])) && ret != 0)
		return (-1);
	if (ret <= 0 && !backup[fd])
		return (ret);
	return (!line) ? -1 : 1;
}

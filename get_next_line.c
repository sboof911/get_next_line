/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:55:17 by amaach            #+#    #+#             */
/*   Updated: 2019/11/10 18:54:43 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(int fd, char *str)
{
	int		len;
	char	*buffer;
	char	*temp;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
		str = ft_strdup("");
	while (ft_strchr(str, '\n') == NULL)
	{
		if ((len = read(fd, buffer, BUFFER_SIZE)) <= 0)
		{
			free(buffer);
			return (0);
		}
		buffer[len] = '\0';
		temp = str;
		str = ft_strjoin(str, buffer);
		free(temp);
		if (len == 0 || str[0] == '\0')
			break;
	}
	free(buffer);
	return (str);
}

int		get_error(int fd, char **line)
{
	char	c;

	if (fd < 0 || !line || BUFFER_SIZE < 0 || read(fd, &c, 0) < 0)
		return (1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*str;
	size_t		len;
	char		*temp;

	len = 0;
	if (get_error(fd, line))
		return (-1);
	if ((str = get_line(fd, str)) == NULL)
		return (0);
	if (!(ft_strchr(str, '\n')))
	{
		if (!(*line = ft_strdup(str)))
			return (-1);
		free(str);
		str = NULL;
		return (0);
	}
	else
	{
		while(str[len] != '\0' && str[len] != '\n')
			len++;
		temp = str;
		*line = ft_substr(str, 0, len);
		str = ft_strdup(temp + len + 1);
		free(temp);
		return (1);
	}
}

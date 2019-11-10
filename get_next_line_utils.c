/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:31:17 by amaach            #+#    #+#             */
/*   Updated: 2019/11/08 17:02:29 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	unsigned char	*str;
	int				i;

	i = 0;
	str = (unsigned char *)s;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*temp;
	char	*s1;
	int		i;

	i = 0;
	s1 = (char *)s;
	if (!(temp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (0);
	while (s1[i] != '\0')
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	j;
	char			*str;

	str = (char *)s;
	j = (unsigned char)c;
	i = 0;
	if (j == '\0')
		return (str + ft_strlen(str));
	while (str[i] != '\0')
	{
		if (str[i] == j)
			return (str + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	t;
	char	*temp;

	if (!s1)
		return (0);
	if (!s2)
		return (ft_strdup(s1));
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	t = -1;
	if (!(temp = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (0);
	if (!temp)
		return (NULL);
	while (++t < i + j)
	{
		if (t < i)
			temp[t] = s1[t];
		else
			temp[t] = s2[t - i];
	}
	temp[t] = '\0';
	return (temp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*temp;
	size_t			j;
	unsigned int	start1;

	start1 = start;
	if (!s)
		return (0);
	j = 0;
	if (start > ft_strlen(s))
		len = 0;
	if (!(temp = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	while (start < start1 + (unsigned int)len && s[start])
	{
		temp[j] = s[start];
		start++;
		j++;
	}
	temp[j] = '\0';
	return (temp);
}

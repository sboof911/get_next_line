/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaach <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:58:03 by amaach            #+#    #+#             */
/*   Updated: 2019/11/10 19:56:16 by amaach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

int main()
{
	int		fd;
	char	*line;
	fd = open("lignes.txt", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	get_next_line(fd, &line);
	printf("\n%s", line);
//	free(line);
	return (0);
}

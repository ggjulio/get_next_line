/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 12:54:48 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/04 17:36:21 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void ft_strdel(char **as)
{
	if (!as)
		return ;
	free(*as);
	*as = NULL;
}

int main(int ac, char **av)
{
	int fd;
	int ret_value;
	char *line;

	line = NULL;
	fd = open(av[1], O_RDONLY);
	(void)fd;
	if (ac > 1)
		if (fd == -1)
			return (-1);
	ret_value = 1;
	while (ret_value == 1)
	{
		ret_value = get_next_line(fd, &line);
		printf("%d |>>| %s\n", ret_value, line);
		ft_strdel(&line);
	}
	close(fd);
	return (0);
}

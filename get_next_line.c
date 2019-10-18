/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:51:24 by juligonz          #+#    #+#             */
/*   Updated: 2019/10/19 00:50:20 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_h"

static int		error(int fd, char **s)
{
	if (fd < 0)
		return (-1)
}

static char		*read_line()
{
	char	buffer[BUFFER_SIZE + 1];
	int		ret;

	while ((ret = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[ret] = '\0';
		// mon strdupcat
	}
}

int		get_next_line(int fd, char **line)
{
	static char	*s;
	size_t		i;

	if (error == -1)
		return (-1);
//	if (*s)
		// already call func
		//do job

	str = readline();
		
	
}

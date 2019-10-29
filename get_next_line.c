/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:51:24 by juligonz          #+#    #+#             */
/*   Updated: 2019/10/29 17:24:01 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		is_endl(char *buffer)
{
	int i;

	i = 0;
	while (!buffer[i])
		if (buffer[i++] == '\n')
			return (1);
	return (0);
}

static int	read_line(int fd, char **line, char *str, size_t idx)
{
	char	buffer[BUFFER_SIZE + 1];
	int		ret;
	int		i;

	while ((ret = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[ret] =  '\0';
		if (is_endl(buffer))
		{
			if (!(malloc(idx * BUFFER_SIZE + 1)))
				return (-1);
			i = 0;
			while (i < ret && buffer[i] != '\n')
			{
				*line[(idx - 1) * BUFFER_SIZE + i] =  buffer[i];
				i++;
			}
			*line[(idx - 1) * BUFFER_SIZE + i] =  '\0';
			return (1);
		}
		else 
			return (read_line(fd, line, str, idx + 1));
	}
	
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	str[BUFFER_SIZE];

	if (fd < 0)
		return (-1);
	return (read_line(fd, line, str, 1) == -1);


	return (0);
}

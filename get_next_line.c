/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:51:24 by juligonz          #+#    #+#             */
/*   Updated: 2019/10/19 13:32:38 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

static int		error(int fd, char *s)
{
	(void)s;
	if (fd < 0)
		return (-1);
}

static int		is_endl(char *buffer)
{
	size_t i;

	i = 0;
	while (i < BUFFER_SIZE)
		if (buffer[i++] == '\n')
			return (1);
	return (0);
}

static void		read_line(int fd, char **str)
{
	char	buffer[BUFFER_SIZE + 1];
	int		ret;

	while ((ret = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[ret] = '\0';
		*str = ft_strdup_cat(*str, buffer);
		if (is_endl(buffer))
			return ;
	}
}

static void		format_line(char **line, char *str)
{
	size_t i;

	i = -1;
	while (str[++i] != '\n')
	{
		
		*line = ft_strdup(&str[i + 1]);
//		str = ft_strdup(&str[i + 1]);
	}
	
}

int		get_next_line(int fd, char **line)
{
	static char	*str;
	size_t		i;

//	if (error(fd) == -1)
//		return (-1);

	read_line(fd, &str);
	format_line(line, str);	
	

	return (0);
}

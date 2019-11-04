/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:51:24 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/03 12:26:23 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

// return -1 of no nl, or return idx of nl
static int	is_endl(char *s, int len)
{
	int i;

	i = -1;
	while (++i < len)
		if (s[i] == '\n')
			return (i);
	return (-1);
}

static int	pop_line(t_str str)
{
	int i;
	int j;
	int	endl_idx;

	if ((endl_idx = is_endl(str.s, str.len)) != -1)
	{
		if (!(*line = malloc(endl_idx + 1)))
			return (-1);
		i = -1;
		while (++i < endl_idx)
			(*line)[i] = str.s[i];
		(*line)[i++] = '\0';
		j = 0;
		while (str.s[i] && i < str.len)
			str.s[j++] = str.s[i];
		str.s[j] = '\0';
		str.len = j;
		return (1);
	}
	return (0);
}


static int	read_line(int fd, char **line, t_str str, int idx)
{
	char	buffer[BUFFER_SIZE];
	int		ret;
	int		i;
	int		endl_idx;

	if (idx == 0 && (ret = pop_line(str)) != 0)
		return (ret);
	if ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if ((endl_idx = is_endl(buffer, BUFFER_SIZE)) != -1)
		{
			
		}
		else 
		{
			
		}
	}

}

int		get_next_line(int fd, char **line)
{
	static t_str	str;
	int ret;

	if (fd < 0 || BUFFER_SIZE < 1 || (ret = read_line(fd, line, str, 0)) == -1)
		return (-1);
	return (ret);
}

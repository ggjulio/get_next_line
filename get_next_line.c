/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:51:24 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/04 15:18:47 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** return -1 of no nl, or return idx of nl
*/

static int	is_endl(char *s, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		if (s[i] == '\n')
			return (i);
	return (-1);
}

static int	pop_line(t_str *str, char **line)
{
	int i;
	int j;
	int	endl_idx;

	if ((endl_idx = is_endl(str->s, str->len)) != -1)
	{
		if (!(*line = malloc(endl_idx + 1)))
			return (-1);
		i = -1;
		while (++i < endl_idx)
			(*line)[i] = str->s[i];
		(*line)[i++] = '\0';
		j = 0;
		while (str->s[i] && i < str->len)
			str->s[j++] = str->s[i++];
		str->s[j] = '\0';
		str->len = j;
		return (1);
	}
	return (0);
}

static int	read_line(int fd, char **line, t_str *str, int idx)
{
	char	buffer[BUFFER_SIZE];
	int		ret;
	int		i;
	int		endl_idx;
	int		is_line;

	if (idx == 0 && (ret = pop_line(str, line)) != 0)
		return (ret);
	if ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if ((endl_idx = is_endl(buffer, BUFFER_SIZE)) != -1)
		{
			if (!(*line = malloc(idx * BUFFER_SIZE + endl_idx + str->len + 1)))
				return (-1);
			i = -1;
			while (++i < str->len)
				(*line)[i] = str->s[i];
			str->s[0] = '\0';
			i = -1;
			while (++i < endl_idx)
				(*line)[idx * BUFFER_SIZE + str->len + i] = buffer[i];
			(*line)[idx * BUFFER_SIZE + str->len + i] = '\0';
			str->old_len = str->len;
			str->len = 0;
			while (++i < ret)
				str->s[str->len++] = buffer[i];
			return (1);
		}
		else
		{
			if ((is_line = read_line(fd, line, str, idx + 1)) == -1)
				return (-1);
			i = -1;
			while (++i < BUFFER_SIZE)
				(*line)[idx * BUFFER_SIZE + str->old_len + i] = buffer[i];
			return (is_line);
		}
	}
	else
	{
		if (!(*line = malloc(idx * BUFFER_SIZE + str->len + 1)))
			return (-1);
		i = -1;
		while (++i < str->len)
			(*line)[i] = str->s[i];
		return (0);
	}
}

int			get_next_line(int fd, char **line)
{
	static t_str	str;
	int				ret;

	if (fd < 0 || BUFFER_SIZE < 1 || (ret = read_line(fd, line, &str, 0)) == -1)
		return (-1);
	return (ret);
}

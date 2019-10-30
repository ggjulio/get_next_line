/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:51:24 by juligonz          #+#    #+#             */
/*   Updated: 2019/10/30 15:48:24 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		is_endl(char *buffer)
{
	int i;

	i = 0;
	while (i < BUFFER_SIZE)
		if (buffer[i++] == '\n')
			return (1);
	return (0);
}

static int	get_str(char *str)
{
	int		i;
	int		j;

	if (is_endl(str))
	{
		if (!(*line = malloc((BUFFER_SIZE + 1)))) // A CHANGER POUR MALLOC LA BONNE TAILLE
			return (-1);
		i = 0;
		j = 0;
		while (str[i] != '\n')
		{
			(*line)[i] =  str[i];
			str[i++] = '\0';
		}
		str[i++] = '\0';
		while (!str[i])
			str[j++] = str[i++];
		str[j] = '\0';
		return (1);
	}
}

static int	read_line(int fd, char **line, char *str, size_t idx)
{
	char	buffer[BUFFER_SIZE + 1];
	int		ret;
	int		i;
	
	if
	while ((ret = read(fd, buffer, BUFFER_SIZE)))
	{
		if (is_endl(buffer))
		{
			if (!(*line = malloc((idx + 1) * BUFFER_SIZE + 1)))
				return (-1);
			i = 0;
			while (i < ret && buffer[i] != '\n')
			{
				(*line)[(idx) * BUFFER_SIZE + i] =  buffer[i];
				i++;
			}
// while missing
			while (++i < ret)
				*str++ =  buffer[i];
			*str = '\0';
			
			(*line)[(idx) * BUFFER_SIZE + i] =  '\0';
			return (ret);
		}
		else 
			return (read_line(fd, line, str, idx + 1));
	}
	
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	str[BUFFER_SIZE];
	int ret;

	if (fd < 0 || (ret = read_line(fd, line, str, 0)) == -1)
		return (-1);
	else if (ret)
		return (1);
	return (0);
}

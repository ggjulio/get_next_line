/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:51:24 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/03 08:55:34 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

// return -1 if no nl, return -2 if \0 in str,
//  or return the size of str before nl. (it can be 0)
static int		is_endl(char *buffer)
{
	int i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buffer[i] == '\n')
			return (i);
		if (buffer[i] == '\0')
			return (-2);			
		i++;
	}
	return (-1);
}

#include <stdio.h>

static int	read_line(int fd, char **line, char *str, int *str_len, int idx)
{
	char	buffer[BUFFER_SIZE];
	int		ret;
	int		i;
	int		j;
	int		endl_idx;
	int		is_line;
	
	if (idx == 0 && (endl_idx = is_endl(str)) >= 0) 
	{
		i = 0;
		if (!(*line = malloc(endl_idx + 1)))
			return (-1);
		while (str[i] != '\n')
		{
			(*line)[i] = str[i];
//			str[i++] = '\0'; // usefull ??
			i++;
		}
		(*line)[i++] = '\0';
//		str[i++] = '\0';
		j = 0;
		while (i < BUFFER_SIZE && str[i])        //move the rest of str at the begining
			str[j++] = str[i++];
		str[j] = '\0';
		*str_len = j;
		return (1);
	}
	
	if ((ret = read(fd, buffer, BUFFER_SIZE)) >= 0) // change while to if
	{
		if ((endl_idx = is_endl(buffer)) >= 0)           // if is nl in actual buffer ERROR HERE if \0
		{
//			printf("|if|%d|\n", idx * BUFFER_SIZE + endl_idx + *str_len + 1);
			if (!(*line = malloc(idx * BUFFER_SIZE + endl_idx + *str_len + 1)))
				return (-1);

			// copy the str if exist and cpy buffer;
			i = -1;
			while (++i < *str_len)
				(*line)[i] = str[i];
			str[0] = '\0';
			i = -1;
			while (++i < ret && buffer[i] != '\n')
				(*line)[(idx) * BUFFER_SIZE + *str_len + i] = buffer[i];
			(*line)[(idx) * BUFFER_SIZE + *str_len + i] = '\0';
			*str_len = 0; 			// copy the rest of the buffer in str;
			while (++i < ret) 
				str[(*str_len)++] = buffer[i];
			if (*str_len < BUFFER_SIZE)
				str[*str_len] = '\0';
			return (1);
		}
		else
		{
			if ((is_line = read_line(fd, line, str, str_len, idx + 1)) == -1)
					return (-1);				
			i = 0;
			while (i < BUFFER_SIZE)
			{
//				(*line)[(idx) * BUFFER_SIZE + *str_len + i] = buffer[i];
				(*line)[(idx) * BUFFER_SIZE + i] = buffer[i];
				i++;
			}
			return (1);
		}
	}
	else 		//malloc and return 0
	{
//		printf("|el|%d|\n", idx * BUFFER_SIZE + *str_len + 1);
		if (!(*line = malloc(idx * BUFFER_SIZE + *str_len + 1))) 
			return (-1);

		i = 0;
		if (idx == 0 && *str_len > 0)
		{
			while (i < *str_len)
			{
				(*line)[i] = str[i];
				i++;
			}
			str[0] = '\0';
			*str_len = 0;
			(*line)[i] = '\0';
			return (1);
		}
		(*line)[i] = '\0';
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	str[BUFFER_SIZE];
	static int	str_len;
	int ret;

	if (fd < 0 || BUFFER_SIZE < 1 || (ret = read_line(fd, line, str, &str_len, 0)) == -1)
		return (-1);
	else if (ret)
		return (1);
	return (0);
}

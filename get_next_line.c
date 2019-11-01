/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:51:24 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/01 19:37:45 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	read_line(int fd, char **line, char *str, int *str_len, size_t idx)
{
	char	buffer[BUFFER_SIZE];
	int		ret;
	int		i;
	int		j;
	int		endl_idx;
	int		is_line;
	
	if (idx == 0 && (endl_idx = is_endl(str)) >= 0) // if there is a \n in str and no recurtion
	{
		i = 0;
		if (!(*line = malloc(endl_idx + 1)))
			return (-1);
		while (str[i] != '\n')
		{
			(*line)[i] = str[i];
			str[i++] = '\0';
		}
		(*line)[i] = '\0';
		j = 0;
       //move the rest of str at the begining
		while (i < BUFFER_SIZE && str[++i]) 
			str[j++] = str[i];
		str[j] = '\0';
		return (1);
	}



	while ((ret = read(fd, buffer, BUFFER_SIZE))) // change while to if
	{
//		if ((endl_idx = is_endl(buffer)) == -2) // if there is a \0
//			return (-1); 
          // if is nl in actual buffer
		endl_idx = is_endl(buffer);
		if (endl_idx != -1) 
		{
			if (!(*line = malloc((idx + 1) * BUFFER_SIZE + *str_len + 1)))
				return (-1);

			i = 0;
			// copy the str if exist and cpy buffer;
			while (i < ret && buffer[i] != '\n')
			{
				if (i < *str_len)
					(*line)[i] = str[i];
				(*line)[(idx) * BUFFER_SIZE + *str_len +i] = buffer[i];
				i++;
			}
			// copy the rest of the buffer in str;
			*str_len = 0;
			while (++i < ret) 
				str[(*str_len)++] = buffer[i];
//			if (i < BUFFER_SIZE - 1)
//				str[*str_len] = '\0';
			return (1);
		}
		else
		{
			if ((is_line = read_line(fd, line, str, str_len, idx + 1)) == -1)
					return (-1);				
			if (!is_line) 			// if read_line return 0 malloc and copy from this idx (EOF)
				if (!(*line = malloc((idx + 1) * BUFFER_SIZE + *str_len + 1)))
					return (-1);
			i = 0;
			while (i < BUFFER_SIZE)
			{
				(*line)[(idx) * BUFFER_SIZE + *str_len +i] = buffer[i];
				i++;
			}
			return (1);
			return (is_line);
		}
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	str[BUFFER_SIZE];
	int	str_len;
	int ret;

	str_len = 0;
	if (fd < 0 || (ret = read_line(fd, line, str, &str_len, 0)) == -1)
		return (-1);
	else if (ret)
		return (1);
	return (0);
}

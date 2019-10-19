/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 09:10:43 by juligonz          #+#    #+#             */
/*   Updated: 2019/10/19 10:55:59 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	unsigned int	i;
	char			*s;

	i = 0;
	if (!(s = malloc(sizeof(*s) * (ft_strlen(src) + 1))))
		return (NULL);
	while (src[i])
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_strdup_cat(char *src, char *buf)
{
	unsigned int	i;
	unsigned int	j;
	char			*s;

	i = 0;
	if (!(s = malloc(sizeof(char) * (ft_strlen(src) + ft_strlen(buf) + 1))))
		return (NULL);
	while (src[i])
	{
		s[i] = src[i];
		i++;
	}
	j = 0;
	while (buf[j])
	{
		s[i + j] = buf[j];
		j++;
	}
	s[i + j] = '\0';
	free(src);
	return (s);
}

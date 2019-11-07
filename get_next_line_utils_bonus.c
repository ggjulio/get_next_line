/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:48:55 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/07 19:19:16 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		multi_fd(t_str *str, int fd)
{
	int i;

	i = 0;
	while (fd != 0 && ++i < FD_MAX)
		if (str[i].fd == fd)
			return (i);
	i = 0;
	while (++i < FD_MAX)
		if (str[i].fd == 0)
		{
			str[i].fd = fd;
			return (i);
		}
	return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:51:14 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/07 16:15:09 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_str
{
	int		fd;
	char	s[BUFFER_SIZE];
	int		len;
	int		old_len;
}				t_str;

typedef struct	s_offsets
{
	int		d;
	int		s;
}				t_offsets;

int				get_next_line(int fd, char **line);

#endif

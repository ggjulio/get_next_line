/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 12:54:48 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/07 12:30:46 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void ft_strdel(char **as)
{
	if (!as)
		return ;
	free(*as);
	*as = NULL;
}

int main(void)
{
	int ret_value;
	char *line;

	
	line = NULL;
	ret_value = 1;
	while (ret_value == 1)
	{
		ret_value = get_next_line(0, &line);
		printf("%d |>>| %s\n", ret_value, line);
		ft_strdel(&line);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:12:25 by hsliu             #+#    #+#             */
/*   Updated: 2022/12/06 15:54:49 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//return NULL when error, or when there's nothing to read
char	*get_next_line(int fd)
{
	char	*buffer;
	int		i;
	char	c;
	int		err;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	i = 0;
	if (buffer == NULL)
		return (buffer);
	while (1)
	{
		err = read(fd, &c, 1);
		if (err == 1)
			buffer[i++] = c;
		else if (err == 0)
			return (buffer);
		else
			return (free(buffer), NULL);
		if (c == '\n')
			return (buffer);
	}
}	

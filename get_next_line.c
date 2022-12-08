/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:12:25 by hsliu             #+#    #+#             */
/*   Updated: 2022/12/08 13:07:21 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//if there's nothing to read, or an error occur
//then return NULL
char	*get_next_line(int fd)
{
	static char	*next = NULL;
	char		buffer[BUFFER_SIZE + 1];
	int			err;

	if (next == NULL)
	{
		next = (char *)malloc(sizeof(char));
		*next = '\0';
	}
	err = ft_read(fd, &next, buffer);
	if (err == -1)
		return (free(next), NULL);
	if (err == -2)
		return (free(next), NULL);
	return (ft_return_line(&next));
}

//it will read and strjoin unti we have a new line in s
//or when there's no more to read
//return 1 normally
//return -1 when read error
//return -2 when malloc error
//return 0 when there's no more to read
int	ft_read(int fd, char **s, char *buf)
{
	char	*s_old;
	int		cnt;

	if (ft_strchr(*s, '\n'))
		return (1);
	while (1)
	{
		cnt = (int)read(fd, buf, BUFFER_SIZE);
		if (cnt == -1)
			return (-1);
		if (cnt == 0)
			return (0);
		buf[cnt] = '\0';
		s_old = *s;
		*s = ft_strjoin((char const *)*s, (char const *)buf);
		if (*s == NULL)
			return (free(s_old), -1);
		free(s_old);
		if (ft_strchr(buf, '\n'))
			return (1);
	}
}

//it will return the next line in 'next'
//the next line is end with a newline or a '\0'
//return NULL when error
char	*ft_return_line(char **next)
{
	int		i;
	char	*new_next;
	char	*ret;

	i = 0;
	while ((*next)[i] && (*next)[i] != '\n')
		i++;
	if ((*next)[i] == '\n')
	{
		new_next = ft_strdup((const char *)&((*next)[i + 1]));
		if (new_next == NULL)
			return (NULL);
		(*next)[i + 1] = '\0';
		ret = *next;
		*next = new_next;
		return (ret);
	}
	if (**next == '\0')
		return (NULL);
	return (*next);
}

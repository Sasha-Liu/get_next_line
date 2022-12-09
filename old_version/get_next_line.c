/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:12:25 by hsliu             #+#    #+#             */
/*   Updated: 2022/12/09 10:35:35 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//if there's nothing to read, or an error occur
//then return NULL

char	*get_next_line(int fd)
{
	static char	*next = NULL;
	static int	eof = FALSE;
	int			err;

	if (next == NULL && eof == FALSE)
	{
		next = (char *)malloc(sizeof(char));
		*next = '\0';
	}
	if (next == NULL && eof == TRUE)
		return (NULL);
	err = ft_read(fd, &next, &eof);
	if (err == -1 || err == -2)
	{
		free(next);
		next = NULL;
		return (NULL);
	}
	return (ft_return_line(&next, &eof));
}

//it will read and strjoin unti we have a new line in s
//or when there's no more to read
//return 1 normally
//return -1 when read error
//return -2 when malloc error
//return 0 when there's no more to read
int	ft_read(int fd, char **next, int *eof)
{
	char	*next_new;
	int		err;
	char	buf[BUFFER_SIZE + 1];

	if (ft_strchr(*next, '\n'))
		return (1);
	while (TRUE)
	{
		err = (int)read(fd, buf, BUFFER_SIZE);
		if (err == -1)
			return (-1);
		if (err < BUFFER_SIZE)
			*eof = TRUE;
		buf[err] = '\0';
		next_new = ft_strjoin((char const *)*next, (char const *)buf);
		free(*next);
		*next = next_new;
		if (*next == NULL)
			return (-1);
		if (ft_strchr(buf, '\n'))
			return (1);
	}
}

//it will return the next line in 'next'
//the next line is end with a newline or a '\0'
//return NULL when error
char	*ft_return_line(char **next, int eof)
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
		if (**next == '\0' && eof == TRUE)
		{
			free(*next);
			*next = NULL;
		}
		return (ret);
	}
	else
	{
		ret = *next;
		*next = NULL;
		return (ret);
	}
}

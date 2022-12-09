/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:38:38 by hsliu             #+#    #+#             */
/*   Updated: 2022/12/09 13:26:34 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	static int	eof = FALSE;
	int			err;
	char		*line;

	err = 0;
	if (str == NULL && eof == FALSE)
	{
		str = (char *)malloc(sizeof(char));
		if (str == NULL)
			return (NULL);
		*str = '\0';
	}
	if (str == NULL && eof == TRUE)
		return (NULL);
	err = ft_read(fd, &str, &eof);
	if (err == -1)
	{
		free(str);
		str = NULL;
		eof = TRUE;
		return (NULL);
	}
	line = ft_give_line(str);
	if (*line == '\0')
	{
		free(line);
		line = NULL;
	}
	ft_trim(&str, eof);
	return (line);
}

//return -1 when error
//return 1 otherwise
//set eof when reaching end of file
int	ft_read(int fd, char **str, int *eof)
{
	char	*new_str;
	char	buffer[BUFFER_SIZE + 1];
	int		count;

	if (ft_strchr(*str, '\n'))
		return (1);
	while (TRUE)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
			return (-1);
		if (count < BUFFER_SIZE)
			*eof = TRUE;
		buffer[count] = '\0';
		new_str = ft_strjoin(*str, buffer);
		free(*str);
		*str = new_str;
		if (ft_strchr(buffer, '\n'))
			return (1);
		if (*eof == TRUE)
			return (1);
	}
}

//there are three possibilities : 
//*str terminate by '\0' and eof = true
//*str terminate by '\n' '\0' and eof = true
//or eof = false
void	ft_trim(char **str, int eof)
{
	int		i;
	size_t	len;

	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if ((*str)[i] == '\0')
	{
		free(*str);			
		*str = NULL;
		return ;
	}
	len = ft_strlen(*str + i + 1);
	if (len == 0)
		**str = '\0';
	else
		ft_memmove(*str, *str + i + 1, len + 1);
	if (**str == '\0' && eof == TRUE)
	{
		free(*str);
		*str = NULL;
	}
}

//malloc using ft_strndup
char	*ft_give_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		line = ft_strndup(str, i);
	if (str[i] == '\n')
		line = ft_strndup(str, i + 1);
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:38:38 by hsliu             #+#    #+#             */
/*   Updated: 2022/12/09 11:31:45 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	static int	eof = FALSE;
	int			err;
	char		*line;

	if (str == NULL && eof == FALSE)
	{
		str = (char *)malloc(sizeof(char));
		if (str == NULL)
			return (NULL);
		*str = '\0';
	}
	if (str == NULL && eof == TRUE)
		return (NULL);
	if (eof == FALSE)
		//ft_read(fd, &str, &eof);
	line = ft_give_line(str);
	if (line == NULL)
		return (NULL);
	ft_trim(&str, eof);
	return (line);
}

void	ft_trim(char **str, int eof)
{
	int		i;
	size_t	len;
	char	*new_str;

	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	len = ft_strlen(*str + i + 1);
	if (len == 0)
		**str = '\0';
	else
		ft_memmove(*str, *str + i + 1, len + 1);
	if (**str == '\0' && eof == TRUE)
		*str = NULL;
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

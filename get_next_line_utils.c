/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:09:16 by hsliu             #+#    #+#             */
/*   Updated: 2022/12/07 18:24:50 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	x;

	x = (char)c;
	while (*s && *s != x)
		s++;
	if (x == *s)
		return ((char *)s);
	return (0);
}

//concatenate s1 and s2 and retrun it
char	*ft_strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*ptr;
	int		i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ptr = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (ptr == 0)
		return (ptr);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[i - len1])
	{
		ptr[i] = s2[i - len1];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strcpy(char *s)
{
	int		len;
	char	*ptr;
	int		i;

	i = 0;
	len = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

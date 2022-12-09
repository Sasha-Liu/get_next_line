/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:09:16 by hsliu             #+#    #+#             */
/*   Updated: 2022/12/09 13:33:29 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	x;
	int		i;

	x = (char)c;
	i = 0;
	while (s[i] && s[i] != x)
		i++;
	if (x == s[i])
		return ((char *)(s + i));
	return (0);
}

//concatenate s1 and s2 and retrun it
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len1;
	size_t		len2;
	char		*ptr;
	int			i;

	len1 = ft_strlen((const char *)s1);
	len2 = ft_strlen((const char *)s2);
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

char	*ft_strndup(const char *s, size_t n)
{
	size_t	len;
	char	*ptr;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	if (n < len)
		len = n;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	while (s[i] && i < len)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest > src)
	{
		while (i < n)
		{
			((char *)dest)[n - i - 1] = ((char *)src)[n - i - 1];
			i++;
		}
	}
	else if (dest < src)
	{
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}

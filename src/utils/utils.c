/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:47:28 by lgrigore          #+#    #+#             */
/*   Updated: 2025/04/06 17:22:31 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	const char	*start;
	int			result;

	start = s;
	while (*s)
		s++;
	result = s - start;
	return (result);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			total_size;
	void			*ptr;
	unsigned char	*byte_ptr;
	size_t			i;

	i = 0;
	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (!ptr)
	{
		return (NULL);
	}
	byte_ptr = (unsigned char *)ptr;
	while (i < total_size)
	{
		byte_ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	char	*new_str;
	int		i;

	new_str = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!new_str)
	{
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		new_str[i] = s[i];
		i++;
	}
	return (new_str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- > 0)
	{
		if (*s1 != *s2)
		{
			return ((unsigned char)(*s1) - (unsigned char)(*s2));
		}
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (0);
}

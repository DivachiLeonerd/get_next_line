/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:20:04 by afonso            #+#    #+#             */
/*   Updated: 2022/04/19 11:49:11 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_realloc(char *saved_string, char *buffer,
					int start, int end)
{
	int		strlen_saved;
	char	*realloc;
	int		buf_len;

	buf_len = end - start + 1;
	strlen_saved = ft_strlen(saved_string, 0);
	realloc = malloc((strlen_saved + buf_len + 1) * sizeof(char));
	if (!realloc)
		return (NULL);
	realloc[strlen_saved + buf_len] = 0;
	while (strlen_saved > 0)
	{
		while (buf_len > 0)
		{
			realloc[strlen_saved + buf_len - 1] = buffer[buf_len - 1];
			buf_len--;
		}
		strlen_saved--;
		realloc[strlen_saved] = saved_string[strlen_saved];
	}
	return (realloc);
}

size_t	ft_strlen(const char *str, unsigned int index)
{
	unsigned int	counter;

	counter = 0;
	str = &str[index];
	while (*str != '\n' && *str != '\0' && index < BUFFER_SIZE)
	{
		counter++;
		str++;
	}
	return (counter);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (NULL);
	if (start < ft_strlen(s, start))
	{
		if (start + len < ft_strlen(s, start))
			str = malloc(sizeof(char) * (len + 1));
		else
			str = malloc(sizeof(char) * (ft_strlen(s, start) - start + 1));
	}
	else
		str = malloc(2 * sizeof(char));
	if (!str)
		return (NULL);
	i = start;
	j = 0;
	while ((start < ft_strlen(s, start) && i < start + len &&
			(s[i] != '\0' || s[i] != '\n')))
		str[j++] = s[i++];
	str[j] = '\n';
	return (str);
}

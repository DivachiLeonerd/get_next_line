/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:20:04 by afonso            #+#    #+#             */
/*   Updated: 2022/05/04 17:48:35 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

unsigned long long	ft_strlen(const char *str)
{
	int	counter;

	counter = 0;
	while (*str)
	{
		counter++;
		str++;
	}
	return (counter);
}

char	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*array;

	array = (unsigned char *)s;
	i = 0;
	while (n > i)
	{
		if (array[i] == (unsigned char)c)
			return ((char *)&array[i]);
		i++;
	}
	return (NULL);
}

void	checking_buffer(char *buf)
{
	int	index;
	int	new_index;

	index = 0;
	new_index = 0;
	if (!buf)
		return ;
	while (buf[index] != '\n' && index < BUFFER_SIZE)
		buf[index++] = 0;
	while (index < BUFFER_SIZE)
	{
		buf[index++] = 0;
		buf[new_index++] = buf[index];
	}
	return ;
}

char	*ft_substr(char *s, unsigned long long start, unsigned long long len)
{
	char				*str;
	unsigned long long	i;
	unsigned long long	j;

	if (!s)
		return (NULL);
	if (start < ft_strlen(s))
	{
		if (start + len < ft_strlen(s))
			str = malloc(sizeof(char) * (len + 1));
		else
			str = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	}
	else
		str = malloc(2 * sizeof(char));
	if (!str)
		return (NULL);
	i = start;
	j = 0;
	printf("Dentro do substr antes do while de trocas\n");
	while ((start < ft_strlen(s) && i < start + len && s[i] != '\0'))
		str[j++] = s[i++];
	str[j] = '\0';
	printf("Dentro do substr antes do checking buffer\n");
	checking_buffer(s);
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*alloc;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i])
		i++;
	while (s2[j] && s2[j] != '\n')
		j++;
	alloc = malloc((i + j + 1) * sizeof(char));
	if (!alloc)
		return (NULL);
	while (s1[i])
	{
		alloc[i] = s1[i];
		i++;
	}
	while (s2[j] && s2[j] != '\n')
		alloc[i++] = s2[j++];
	alloc[i] = '\0';
	checking_buffer(s2);
	return (alloc);
}

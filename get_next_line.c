/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:30:52 by afonso            #+#    #+#             */
/*   Updated: 2022/05/04 18:40:56 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char			buf[BUFFER_SIZE];
	int					bytes_read;
	unsigned long long	newline;
	char				*saved;
	int					index;

	index = 0;
	if (fd < 0)
		return (NULL);
	printf("buffer:%s\n", buf);
	if (buf[0] == 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 1)
			return (NULL);
	}
	newline = (unsigned long long)(ft_memchr(buf, '\n', BUFFER_SIZE) - &buf[0]);
	if (ft_memchr(buf, '\n', BUFFER_SIZE) == 0)
		saved = ft_substr(buf, (unsigned long long)0, ft_strlen(buf));
	else
	{
		saved = ft_substr(buf, 0, newline);
		printf("newline - &buf[0]=%llu\n", newline);
	}
	printf("Antes do ultimo while\n");
	while (ft_memchr(buf, '\n', BUFFER_SIZE) == 0)
	{
		printf("while do newline = 0:\n");
		checking_buffer(buf);
		read(fd, buf, BUFFER_SIZE);
		newline = (unsigned long long)(ft_memchr(buf, '\n', BUFFER_SIZE) - &buf[0]);
		ft_strjoin(saved, buf);
	}
	return (saved);
}

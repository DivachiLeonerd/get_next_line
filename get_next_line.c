/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:30:52 by afonso            #+#    #+#             */
/*   Updated: 2022/05/06 13:21:09 by afonso           ###   ########.fr       */
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

	if (fd < 0)
		return (NULL);
	if (buf[0] == 0)
		bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read < 1)
		return (NULL);
	newline = (unsigned long long)(ft_memchr(buf, '\n', BUFFER_SIZE) - &buf[0]);
	if (ft_memchr(buf, '\n', BUFFER_SIZE) == 0)
		saved = ft_substr(buf, (unsigned long long)0, ft_strlen(buf));
	else
		saved = ft_substr(buf, 0, newline);
	while (ft_memchr(buf, '\n', BUFFER_SIZE) == 0 && bytes_read != 0)
	{
		checking_buffer(buf);
		bytes_read = read(fd, buf, BUFFER_SIZE);
		saved = ft_strjoin(saved, buf);
	}
	checking_buffer(buf);
	return (saved);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:56:36 by atereso-          #+#    #+#             */
/*   Updated: 2022/05/17 12:56:41 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char			buf[10000][BUFFER_SIZE];
	int					bytes_read;
	unsigned long long	newline;
	char				*saved;

	bytes_read = 1;
	if (fd < 0)
		return (NULL);
	if (buf[fd][0] == 0)
		bytes_read = read(fd, buf[fd], BUFFER_SIZE);
	if (bytes_read < 1)
		return (NULL);
	newline = (unsigned long long)(ft_memchr(buf[fd], '\n', BUFFER_SIZE) - buf[fd]);
	if (ft_memchr(buf[fd], '\n', BUFFER_SIZE) == 0)
		saved = ft_substr(buf[fd], (unsigned long long)0, ft_strlen(buf[fd]));
	else
		saved = ft_substr(buf[fd], 0, newline + 1);
	while (ft_memchr(buf[fd], '\n', BUFFER_SIZE) == 0 && bytes_read != 0)
	{
		checking_buffer(buf[fd]);
		bytes_read = read(fd, buf[fd], BUFFER_SIZE);
		saved = ft_strjoin(saved, buf[fd]);
	}
	checking_buffer(buf[fd]);
	return (saved);
}

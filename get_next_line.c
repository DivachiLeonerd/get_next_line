/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:30:52 by afonso            #+#    #+#             */
/*   Updated: 2022/04/20 12:41:34 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "get_next_line.h"

int	search_line(char *buf, int index)
{
	while (buf[index] != '\n' && buf[index] != '\0' && index < BUFFER_SIZE)
	{
		if (index < BUFFER_SIZE - 1)
			index++;
		else
			break ;
	}
	if (index == BUFFER_SIZE - 1 && buf[index] != '\n' && buf[index] != '\0')
		return (-1);
	else
		return (index);
}

char	*get_line(char *buf, int index, int fd, int mode)
{
	int		is_line;
	char	*saved;

	is_line = search_line(buf, index);
	if (is_line < 0 || mode == 1)
	{
		if (mode == 0)
			saved = ft_substr(buf, index, BUFFER_SIZE - index);
		if (mode == 1)
			saved = ft_realloc(saved, buf, index, is_line);
		if (search_line(saved, 0) >= 0)
			return (saved);
		else
			read(fd, buf, BUFFER_SIZE);
		return (get_line(buf, 0, fd, 1));
	}
	else
		return (ft_substr(buf, index, is_line - index));
}

void	*checking_buffer(char *buf, int index, int fd)
{
	if (!buf)
		return (NULL);
	while (buf[index] == '\0' && index < BUFFER_SIZE)
	{
		if (index < BUFFER_SIZE - 1)
			index++;
		else
			break ;
	}
	if (buf[index] == '\0' && index == BUFFER_SIZE - 1)
	{
		index = 0;
		read(fd, buf, BUFFER_SIZE);
		if (buf[0] == '\0')
			return (NULL);
	}
	return (get_line(buf, index, fd, 0));
}

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE];
	int				index;

	index = 0;
	if (fd < 0)
		return (NULL);
	return (checking_buffer(buf, index, fd));
}

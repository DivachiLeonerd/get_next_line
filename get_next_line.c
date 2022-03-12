/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:30:52 by afonso            #+#    #+#             */
/*   Updated: 2022/03/12 13:15:10 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static unsigned int	how_many_bytes_read;
	void				*buf[BUFFER_SIZE];
	unsigned int		i;
	unsigned int		newline_marker;
	char 				*temp_alloc;

	i = 0;
	buf[BUFFER_SIZE] = '\0';
	how_many_bytes_read = read(fd, buf, BUFFER_SIZE);
	while (buf[i])
	{
		if (buf[i] == '\n' && i < BUFFER_SIZE - 1)
			temp_alloc = save_buffer(buf, i);
	}
}

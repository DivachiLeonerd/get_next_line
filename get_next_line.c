/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:30:52 by afonso            #+#    #+#             */
/*   Updated: 2022/03/29 11:04:32 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char				buf[BUFFER_SIZE];
	static int			buf_index;
	char				big_lines[10000000];
	int					start;
	int					is_eof;

	buf_index = 0;
	start = 0;
	if (buf_index == BUFFER_SIZE)
	{
		is_eof = read(fd, buf, BUFFER_SIZE);
		if (!is_eof)
			return (NULL);
		buf_index = 0;
		get_next_line(fd);
	}
	else
	{
		read(fd, buf, BUFFER_SIZE);
		return (option_handler(buf_index, buf, fd));
	}
}


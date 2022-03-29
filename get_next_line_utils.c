/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:20:04 by afonso            #+#    #+#             */
/*   Updated: 2022/03/29 11:44:16 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*realloc_cat_buffer(char *saved_string,
			char *buffer, int index, char *big_lines)
{
	int				strlen_saved;
	char			*realloc;
	int				tmp_index;
	int				tmp_strlen_saved;


}

char	*save_buffer(char *buffer, int start, int end, char *big_lines)
{
	int				i;
	char			*saved_string;
	int				strlen;
	char			*ptr_realloc;

	i = 0;
	while (buffer[i] != '\n' && i < BUFFER_SIZE)
		big_lines[i] = buffer[start + end];
	return (saved_string);
}

char	*option_handler(int index, char *buf, int fd, char *big_lines)
{
	int				start;
	char			*saved_string;

	start = index;
	while (buf[index] != '\n' && index < BUFFER_SIZE)
		index++;
	if (index < BUFFER_SIZE)
		return (buf);
	if (index == BUFFER_SIZE - 1)
	{
		if (buf[index] == '\n')
			return (&buf[start]);
		if (buf[index] != '\n')
		{
			saved_string = save_buffer(buf, start, BUFFER_SIZE, big_lines);
			index = 0;
			read(fd, buf, BUFFER_SIZE);
			while (buf[index] != '\n')
				index++;
			return (realloc_cat_buffer(saved_string, buf, index, big_lines));
		}
	}
}

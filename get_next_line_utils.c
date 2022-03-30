/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:20:04 by afonso            #+#    #+#             */
/*   Updated: 2022/03/29 19:42:43 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*realloc_cat_buffer(char *saved_string, char *buffer, int index)
{
	int				strlen_saved;
	char			*realloc;
	int				tmp_index;
	int				tmp_strlen_saved;

	tmp_index = index;
	strlen_saved = 0;
	while (saved_string[strlen_saved])
		strlen_saved++;
	tmp_strlen_saved = strlen_saved;
	realloc = malloc((strlen_saved + (index + 1) + 2) * sizeof(char));
	while (strlen_saved)
	{
		while (index + 1)
			realloc[strlen_saved + index] = buffer[index--];
		realloc[strlen_saved] = saved_string[--strlen_saved];
	}
	index = 0;
	realloc[tmp_strlen_saved + (tmp_index + 1)] = '\0';
	realloc[tmp_strlen_saved + (tmp_index + 1) + 1] = 'a';
	return (realloc);
}

char	*save_buffer(char *buffer, int start, int end)
{
	int				i;
	char			*saved_string;
	int				strlen;
	char			*ptr_realloc;

	i = start;
	while (i < end)
		i++;
	strlen = i - start;
	i = 0;
	saved_string = malloc(strlen * sizeof(char));
	while (start < end)
		saved_string[i++] = buffer[start++];
	return (saved_string);
}

char	*option_handler(int index, char *buf, int fd)
{
	int				start;
	char			*saved_string;

	start = index;
	while (buf[index] != '\n' && index < BUFFER_SIZE - 1)
		index++;
	if (index < BUFFER_SIZE - 1)
		return (save_buffer(buf, start, index));
	if (index == BUFFER_SIZE - 1)
		if (buf[index] == '\n')
			return (&buf[start]);
	if (buf[index] != '\n')
	{
		saved_string = save_buffer(buf, start, BUFFER_SIZE);
		read(fd, buf, BUFFER_SIZE);
		while (buf[index] != '\n')
			index++;
		return (realloc_cat_buffer(saved_string, buf, index));
	}
}

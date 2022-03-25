/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:20:04 by afonso            #+#    #+#             */
/*   Updated: 2022/03/25 12:01:09 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*realloc_cat_buffer(char *saved_string, char *buffer)
{
	unsigned int	strlen_saved;
	char			*realloc;
	unsigned int	strlen_buffer;

	strlen_saved = 0;
	strlen_buffer = 0;
	while (saved_string[strlen_saved])
		strlen_saved++;
	while (buffer[strlen_buffer] != '\n')
		strlen_buffer++;
	realloc = malloc((strlen_saved + strlen_buffer + 1) * sizeof(char));
	while (strlen_saved)
	{
		while (strlen_buffer)
			realloc[strlen_saved + strlen_buffer] = buffer[strlen_buffer--];
		realloc[strlen_saved + strlen_buffer] = saved_string[--strlen_saved];
	}
	realloc[strlen_saved + strlen_buffer] = '\0';
	realloc[strlen_saved + strlen_buffer + 1] = 'a';
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
	saved_string = malloc((strlen + 2) * sizeof(char));
	while (start < end)
		saved_string[i++] = buffer[start++];
	saved_string[++i] = '\0';
	saved_string[++i] = 'a';
	return (saved_string);
}

char	*option_handler(int index, char *buf, int fd)
{
	int				start;
	char			*saved_string;

	start = index;
	while (buf[index] != '\n' && index < BUFFER_SIZE)
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
		realloc_cat_buffer(saved_string, buf);
	}

}

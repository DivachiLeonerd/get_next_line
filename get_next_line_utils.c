/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:20:04 by afonso            #+#    #+#             */
/*   Updated: 2022/03/12 13:11:49 by afonso           ###   ########.fr       */
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
	while (buffer[strlen_buffer])
		strlen_buffer++;
	realloc = malloc((strlen_saved + strlen_buffer + 1) * sizeof(char));
	while (strlen_saved)
	{
		while (strlen_buffer)
			realloc[strlen_saved + strlen_buffer] = buffer[strlen_buffer--];
		realloc[strlen_saved + strlen_buffer] = saved_string[--strlen_saved];
	}
	return (realloc);
}

char	*save_buffer(char *buffer, unsigned int start)
{
	unsigned int	i;
	char			*saved_string;
	unsigned int	strlen;

	i = start;
	while (buffer[i])
		i++;
	strlen = i - start;
	i = 0;
	saved_string = malloc((strlen + 1) * sizeof(char));
	while (buffer[start])
		saved_string[i++] = buffer[start++];
	return (saved_string);
}

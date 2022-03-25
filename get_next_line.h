/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:33:44 by afonso            #+#    #+#             */
/*   Updated: 2022/03/17 16:40:22 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*get_next_line_utils(int fd);
char	*save_buffer(char *buffer, unsigned int start);
char	*realloc_cat_buffer(char *saved_string, char *buffer);
void	function_handler(char *buf);
int		BUFFER_SIZE;

#endif

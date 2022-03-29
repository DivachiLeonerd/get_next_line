/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:33:44 by afonso            #+#    #+#             */
/*   Updated: 2022/03/29 11:48:23 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*get_next_line_utils(int fd);
char	*save_buffer(char *buffer, int start, int end, char *big_lines);
char	*realloc_cat_buffer(char *saved_string, char *buffer,
			int index, char *big_lines);
char	*option_handler(int index, char *buf, int fd, char *big_lines);

#endif

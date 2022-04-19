/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:33:44 by afonso            #+#    #+#             */
/*   Updated: 2022/04/18 17:40:15 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_realloc(char *saved_string, char *buffer, int start, int end);
size_t	ft_strlen(const char *str, unsigned int index);
void	*checking_buffer(char *buf, int index, int fd);
char	*get_line(char *buf, int index, int fd, int mode);
int		search_line(char *buf, int index);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:55:26 by atereso-          #+#    #+#             */
/*   Updated: 2022/05/17 12:55:42 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

char				*get_next_line(int fd);
char				*ft_substr(char *s, unsigned long long start,
						unsigned long long len);
char				*ft_realloc(char *saved_string, char *buffer,
						int start, int end);
char				*ft_memchr(const void *s, int c, size_t n);
void				checking_buffer(char *buf);
char				*get_line(char *buf, int index, int fd, int mode);
unsigned long long	ft_strlen(const char *str);
char				*ft_strjoin(char *saved, char *buf);
#endif

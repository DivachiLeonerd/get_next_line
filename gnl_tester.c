/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_tester.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:28:46 by afonso            #+#    #+#             */
/*   Updated: 2022/03/29 19:44:07 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>

void	helper(int x)
{
	x == x + 1;
	printf("%d\n", x);
}

void	main_helper(void)
{
	char	buf[42];
	int		fd;
	char	*buffer;
	int		i;

	i = 0;
	fd = open("./fd_test.txt", O_RDONLY);
	printf("abri o fd:%d\n", fd);
	while (i < 2)
	{
		printf("(text)%s(text)\n", buffer = get_next_line(fd));
		free(buffer);
		i++;
	}
	fd = close(fd);
}

void	main(void)
{
	main_helper();
}

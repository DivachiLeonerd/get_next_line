/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_tester.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:28:46 by afonso            #+#    #+#             */
/*   Updated: 2022/05/12 16:34:39 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int		fd = 0;
	char	*tmp = NULL;
	int		i = 0;

	fd = open("./fd_test.txt", O_RDONLY);
	if (!fd)
	{
		printf("Nao abriu:%d\n", fd);
		return (fd);
	}
	printf("abriu\n");
	while (i < 10)
	{
		printf("Is get_next_line working?:%s", tmp = get_next_line(fd));
		if (tmp)
			free(tmp);
		tmp = NULL;
		i++;
	}
	close(fd);
}

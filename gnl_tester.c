/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_tester.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:28:46 by afonso            #+#    #+#             */
/*   Updated: 2022/03/23 17:30:05 by afonso           ###   ########.fr       */
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

void	main_helper()
{
	char buf[43];
	int fd;
	static char string[] = "Hello There\n";
	static int x = 0;
	buf[42] = '\0';
	fd = close(fd);
	fd = open("./fd_test.txt", O_RDONLY);
	printf("fd_test.txt: %ld\n", read(fd, buf, 42));
	printf("text: %s\n", buf);
	printf("fd_test.txt: %ld\n", read(fd, buf, 42));
	printf("text: %s\n", buf);
	printf("fd_test.txt: %ld\n", read(fd, buf, 42));
	printf("text: %s\n", buf);
	printf("fd_test.txt: %ld\n", read(fd, buf, 42));
	printf("text: %s\n", buf);
	printf("fd_test.txt: %ld\n", read(fd, buf, 42));
	printf("text: %s\n", buf);
	printf("fd_test.txt: %ld\n", read(fd, buf, 42));
	printf("text: %s\n", buf);
	printf("fd_test.txt: %ld\n", read(fd, buf, 42));
	printf("text: %s\n", buf);
	printf("fd_test.txt: %ld\n", read(fd, buf, 42));
	printf("text: %s\n", buf);
	fd = close(fd);
	x += 1;
	while (x < 4)
	{
		string[0] += 1;
		printf("%s", string);
		main_helper(x);
	}
}

int	main(void)
{
	main_helper();
	main_helper();
}

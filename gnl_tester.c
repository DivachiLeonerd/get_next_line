/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_tester.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:28:46 by afonso            #+#    #+#             */
/*   Updated: 2022/05/04 16:43:48 by atereso-         ###   ########.fr       */
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
	char	buf[BUFFER_SIZE] = "ola\nadeus\n";
	char	*tmp = NULL;
	int		i = 0;

	fd = open("./fd_test.txt", O_RDONLY);
	if (!fd)
	{
		printf("Nao abriu:%d\n", fd);
		return (fd);
	}
	printf("abriu\n");
	// printf("Whats the \\n index number?:%d\n", i = search_line("\0", 0));
	// printf("is Buffer checking working with a string full of \\0?: %s\n", tmp = checking_buffer(buf, 0, fd));
	// printf("Is buf checking good when there is something not \\0?: %s\n", tmp = checking_buffer(buf, 0, fd));
	// if (tmp)
	// 	free(tmp);
	// tmp = NULL;
	// printf("\n****************Utils******************\n");
	// printf("\nft_strlen:%ld\n", ft_strlen("about my cock sucking\n", 0));
	// printf("\nft_substr:%s\n", tmp = ft_substr(buf, 0, 4));
	// if (tmp)
	// 	free(tmp);
	// tmp = NULL;
	// printf("\nRealloc:%s\n", tmp = ft_realloc("Eu", " sou gay\n", 0, search_line(" sou gay\n", 0)));
	// if (tmp)
	// 	free(tmp);
	// tmp = NULL;
	// printf("\n*******************************************************\n");
	// printf("Is get_line working?:%s\n", tmp = get_line(buf, 0, fd, 0));
	// if (tmp)
	// 	free(tmp);
	// tmp = NULL;
	// checking_buffer(buf);
	// printf("Checking buffer:%s", buf);
	checking_buffer(buf);
	printf("buffer depois do checking:%s",buf);
	while (i < 6)
	{
		printf("\nIs get_next_line working?:%s\n\n", tmp = get_next_line(fd));
		if (tmp)
			free(tmp);
		tmp = NULL;
		i++;
	}
	close(fd);
}

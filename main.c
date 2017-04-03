/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 22:47:17 by lchety            #+#    #+#             */
/*   Updated: 2017/04/03 02:12:48 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int		main(void)
{
	char buff[64000];
	char tmp[54000];
	//char bite[] = "gkjsgkjsnegkjs43333333ndgksezkgfuhgef\0";
	int ret;
	int fd;

	ret = 1;

	fd = open("out_file", O_RDWR | S_IRWXU);

	//printf("test =>%d\n", fd);

	while(read(fd, tmp, 1))
	{

	}

	//write(fd, "CACA", 4);
	printf("%d\n", STDIN_FILENO);
	while(read(STDIN_FILENO, buff, 1))
	{
		if (*buff != '\0')
			write(fd, buff, 1);
		if (ft_strstr(buff, "fin"))
			break;
		if (ft_strstr(buff, "error"))
			break;

	}

	//
	// while (ret < 10)
	// {
	// 	write(fd, "bite\n", 5);
	// 	ret++;
	// }
	close(fd);


	// while (1)
	// 	write(1, "2 2\n", 4);
	// while(ret)
	// {
	// 	read(1, buff, 120);
	// 	// if (ft_strstr(buff, "fin"))
	// 	// 	ret = 0;
	// 	printf("HHHHHHHHHHHHHH\n");
	// 	printf("b\n");
	// }

	//printf("bite => %s *\n", buff);


	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 22:47:38 by orazafin          #+#    #+#             */
/*   Updated: 2017/09/19 22:47:59 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdfhead.h"

static int			check_file(int fd)
{
	char buf[1];
	if (read(fd, buf, 1) <= 0)
		return (-1);
	return (1);
}

int					open_file(char *av)
{
	int fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		perror(av);
		exit(EXIT_FAILURE);
	}
	if (check_file(fd) == -1)
		return (0);
	return (fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:40:59 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/05 11:49:43 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	check_and_open_file(char *av, int *fd)
{
	if (check_file(av))
			return (printf("Error: enter a valid map format :*.cub"));
	*fd = open(av, O_RDONLY);
	if (*fd == -1)
		return (printf("%s\n", strerror(errno)));
	return (0);
}

int main(int ac, char **av)
{
	int		fd;
	t_map	*map;

	if (ac == 2)
	{
		if (check_and_open_file(av[1], &fd))
			return (-1);
		map = get_map(fd, av[1]);
		if (!map)
			return (printf("Error: map not acquired\n"));
		free_and_close(map, fd);
	}
	else if (ac == 1)
		printf("Error: usage: ./cub3D [\"path/to/map\"]\n");
	else
		printf("Error: too many arguments00\n");
	return (0);
}

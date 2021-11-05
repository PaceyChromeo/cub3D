/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkrifa <hkrifa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:40:59 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/05 11:36:33 by hkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int main(int ac, char **av)
{
	int		fd;
	t_map	*map;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (printf("%s\n", strerror(errno)));
		map = get_map(fd);
		if (!map)
			return (printf("Error: map not acquired\n"));
		
		close(fd);
		free_map(map);
	}
	else if (ac == 1)
		printf("Error: usage: ./cub3D [\"path/to/map\"]\n");
	else
		printf("Error: too many arguments\n");
	return (0);
}

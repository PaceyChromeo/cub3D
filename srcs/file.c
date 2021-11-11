/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:46:49 by pacey             #+#    #+#             */
/*   Updated: 2021/11/11 09:23:28 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	check_file(char *file)
{
	int	i;

	i = 0;
	if (!file[i] || file[i] == '.')
		return (1);
	while (file[i] && file[i] != '.')
		i++;
	if (file[i++] != '.')
		return (1);
	else
	{
		if (file[i++] != 'c')
			return (1);
		if (file[i++] != 'u')
			return (1);
		if (file[i++] != 'b')
			return (1);
		if (file[i])
			return (1);
	}
	return (0);
}

int	check_texture_file(char *file)
{
	int	i;

	i = 0;
	printf("file : %s\n", file);
	if (!file[i] || file[i] == '.')
		return (printf("Error: enter a valid texture format :*.xpm"));
	printf("OK\n");
	while (file[i] && file[i] != '.')
		i++;
	if (file[i++] != '.')
		return (printf("Error: enter a valid textutr format :*.xpm"));
	else
	{
		if (file[i++] != 'x')
			return (printf("Error: enter a valid textutr format :*.xpm"));
		if (file[i++] != 'p')
			return (printf("Error: enter a valid textutr format :*.xpm"));
		if (file[i++] != 'm')
			return (printf("Error: enter a valid textutr format :*.xpm"));
		if (file[i])
			return (printf("Error: enter a valid textutr format :*.xpm"));
	}
	return (0);	
}
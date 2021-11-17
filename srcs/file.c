/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:46:49 by pacey             #+#    #+#             */
/*   Updated: 2021/11/17 13:13:26 by pjacob           ###   ########.fr       */
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
	if (!file || !file[i] || (file[i] == '.' && file[i + 1] != '/'))
		return (printf("Error: enter a valid texture format :*.xpm\n"));
	else if (file[i] == '.' && file[i + 1] == '/')
		i++;
	while (file[i] && file[i] != '.')
		i++;
	if (file[i++] != '.')
		return (printf("Error: enter a valid texture format :*.xpm\n"));
	else
	{
		if (file[i++] != 'x')
			return (printf("Error: enter a valid texture format :*.xpm\n"));
		if (file[i++] != 'p')
			return (printf("Error: enter a valid texture format :*.xpm\n"));
		if (file[i++] != 'm')
			return (printf("Error: enter a valid texture format :*.xpm\n"));
		if (file[i])
			return (printf("Error: enter a valid texture format :*.xpm\n"));
	}
	return (0);
}

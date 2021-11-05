/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:46:49 by pacey             #+#    #+#             */
/*   Updated: 2021/11/05 11:43:03 by pjacob           ###   ########.fr       */
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
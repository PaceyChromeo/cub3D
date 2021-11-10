/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkrifa <hkrifa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:14:51 by hkrifa            #+#    #+#             */
/*   Updated: 2021/11/10 17:08:09 by hkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int count_lines(char **tmp, int i)
{
	int count;

	count = 0;
	while (tmp[i] != NULL)
	{
		count++;
		i++;
	}
	return (count);
}

int get_max(char **tmp, int i)
{
	int max;
	
	max = 0;
	while (tmp[i])
	{
		if ((int)ft_strlen(tmp[i]) > max)
			max = ft_strlen(tmp[i]);
		i++;
	}
	return (max);
}

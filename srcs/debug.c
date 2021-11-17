/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:28:36 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/17 17:05:19 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	print_or_count_tab(char **tab, int poc)
{
	int	i;

	i = 0;
	if (poc)
		printf("------------BEGIN OF TAB-------------\n");
	while (tab[i])
	{
		if (poc)
			printf("%s\n", tab[i]);
		i++;
	}
	if (poc)
		printf("------------END OF TAB-------------\n");
	return (i);
}

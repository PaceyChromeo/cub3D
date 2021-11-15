/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacob <pjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:54:31 by pjacob            #+#    #+#             */
/*   Updated: 2021/11/15 11:28:30 by pjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	close_win(void)
{
	exit (0);
}

int	deal_keys(int keycode, t_map *map)
{
	if (keycode == ESC)
		close_win();
	else if (keycode == W_KEY)
		deal_up_key(map);
	else if (keycode == A_KEY)
		deal_left_key(map);
	else if (keycode == S_KEY)
		deal_down_key(map);
	else if (keycode == D_KEY)
		deal_right_key(map);
	else if (keycode == L_KEY)
		deal_left_arrow(map);
	else if (keycode == R_KEY)
		deal_right_arrow(map);
	return (0);
}

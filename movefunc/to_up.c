/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_up.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:06:41 by satushi           #+#    #+#             */
/*   Updated: 2022/12/19 17:06:41 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void to_up(int *x, int *y, t_game *param)
{
	if ((param->map->map_str)[*y - 1][*x] != '1')
	{
		*y = *y - 1;
		printf("pushed keycode is right,x is %d, y is %d\n",*x,*y);
		mlx_put_image_to_window(param->mlx, param->win, param->img_player, (*x) * 32, (*y) * 32);
		mlx_put_image_to_window(param->mlx, param->win, param->img_tile, (*x) * 32, (*y) * 32 + 32);
	}
}
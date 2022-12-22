/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_right.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:06:38 by satushi           #+#    #+#             */
/*   Updated: 2022/12/19 17:06:38 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void to_right(int *x, int *y, t_game *param)
{
	if ((param->map->map_str)[*y][*x + 1] != '1')
	{
		printf("players's next area is %c", (param->map->map_str)[*y][*x + 1]);
		printf("pushed keycode is right,x is %d, y is %d\n",*x,*y);
		*x = *x + 1;
		printf("pushed keycode is right,x is %d, y is %d\n",*x,*y);
		mlx_put_image_to_window(param->mlx, param->win, param->img_player, (*x) * 32, (*y) * 32);
		mlx_put_image_to_window(param->mlx, param->win, param->img_tile, (*x) * 32 - 32, (*y) * 32);
		printf("pushed keycode is right,x is %d, y is %d\n",*x,*y);
	}
}
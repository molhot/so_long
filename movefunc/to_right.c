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
	printf("%d\n", param->map->width - 1);
	if (*x == param->map->width - 1)
		return ;
	*x = *x + 1;
	mlx_put_image_to_window(param->mlx, param->win, param->img_player, (*x) * 32, (*y) * 32);
	mlx_put_image_to_window(param->mlx, param->win, param->img_tile, (*x) * 32 - 32, (*y) * 32);
	printf("pushed keycode is right,x is %d, y is %d\n",*x,*y);
}
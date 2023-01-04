/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_left.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:06:35 by satushi           #+#    #+#             */
/*   Updated: 2022/12/19 17:06:35 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	to_left(int *x, int *y, int *c_num, t_game *param)
{
	if ((param->map->map_str)[*y][*x - 1] != '1')
	{
		if (*c_num == 0 && (param->map->map_str)[*y][*x - 1] == 'E')
		{
			printf("END\n\n\n");
			return ;
		}
		else if (*c_num != 0 && (param->map->map_str)[*y][*x - 1] == 'E')
		{
			printf("NOT END !!!!!!!!\n\n\n");
			return ;
		}
		if ((param->map->map_str)[*y][*x - 1] == 'C' && *c_num != 0)
		{
			*c_num = *c_num - 1;
			printf("collect num is %d\n", *c_num);
		}
		*x = *x - 1;
		(param->map->map_str)[*y][*x + 1] = '0';
		(param->map->map_str)[*y][*x] = 'P';
		printf("players x place is %d and y place is %d", *x, *y);
		mlx_put_image_to_window(param->mlx, param->win, \
		param->img_player, (*x) * 32, (*y) * 32);
		mlx_put_image_to_window(param->mlx, param->win, \
		param->img_tile, (*x) * 32 + 32, (*y) * 32);
	}
}

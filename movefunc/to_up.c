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

void to_up(int *x, int *y, int *c_num, t_game *param)
{
	if ((param->map->map_str)[*y - 1][*x] != '1')
	{
		if (*c_num == 0 && (param->map->map_str)[*y - 1][*x] == 'E')
		{
			printf("END");
			return ;
		}
		else if (*c_num != 0 && (param->map->map_str)[*y - 1][*x] == 'E')
		{
			printf("NOT END !!!!!!!!\n\n\n");
			return ;
		}
		if ((param->map->map_str)[*y - 1][*x] == 'C'  && *c_num != 0)
		{
			*c_num = *c_num - 1;
			printf("collect num is %d\n", *c_num);
		}
		*y = *y - 1;
		(param->map->map_str)[*y][*x] = '0';
		printf("players x place is %d and y place is %d", *x, *y);
		mlx_put_image_to_window(param->mlx, param->win, param->img_player, (*x) * 32, (*y) * 32);
		mlx_put_image_to_window(param->mlx, param->win, param->img_tile, (*x) * 32, (*y) * 32 + 32);
	}
}
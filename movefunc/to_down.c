/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_down.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:06:32 by satushi           #+#    #+#             */
/*   Updated: 2022/12/19 17:06:32 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	to_down(int *x, int *y, int *c_num, t_game *param)
{
	if ((param->map->map_str)[*y + 1][*x] != '1')
	{
		if (*c_num == 0 && (param->map->map_str)[*y + 1][*x] == 'E')
			exit_game(param);
		else if (*c_num != 0 && (param->map->map_str)[*y + 1][*x] == 'E')
		{
			ft_printf("You must collect item");
			return ;
		}
		if ((param->map->map_str)[*y + 1][*x] == 'C' && *c_num != 0)
			*c_num = *c_num - 1;
		*y = *y + 1;
		param->moved_count = param->moved_count + 1;
		ft_printf("move count is %d\n", param->moved_count);
		(param->map->map_str)[*y - 1][*x] = '0';
		(param->map->map_str)[*y][*x] = 'P';
		mlx_put_image_to_window(param->mlx, param->win, param -> img_player, \
		(*x) * 32, (*y) * 32);
		mlx_put_image_to_window(param->mlx, param->win, \
		param -> img_tile, (*x) * 32, (*y) * 32 - 32);
	}
}

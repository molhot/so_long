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

static	void	not_ended_inexit(int *x, int *y, int *c_num, t_game *param)
{
	ft_printf("You must collect item\n");
	if ((param->map->map_str)[*y - 1][*x] == 'C' && *c_num != 0)
		*c_num = *c_num - 1;
	*y = *y - 1;
	param->moved_count = param->moved_count + 1;
	ft_printf("move count is %d\n", param->moved_count);
	(param->map->map_str)[*y + 1][*x] = '0';
	(param->map->map_str)[*y][*x] = 'L';
	mlx_put_image_to_window(param->mlx, param->win, \
	param->p_ongoal, (*x) * 32, (*y) * 32);
	mlx_put_image_to_window(param->mlx, param->win, \
	param->img_tile, (*x) * 32, (*y) * 32 + 32);
}

static	void	out_exit(int *x, int *y, int *c_num, t_game *param)
{
	*y = *y - 1;
	param->moved_count = param->moved_count + 1;
	ft_printf("move count is %d\n", param->moved_count);
	(param->map->map_str)[*y + 1][*x] = 'E';
	(param->map->map_str)[*y][*x] = 'P';
	mlx_put_image_to_window(param->mlx, param->win, \
	param->img_goal, (*x) * 32, (*y) * 32 + 32);
	mlx_put_image_to_window(param->mlx, param->win, \
	param->img_player, (*x) * 32, (*y) * 32);
}

void	to_up(int *x, int *y, int *c_num, t_game *param)
{
	if ((param->map->map_str)[*y - 1][*x] != '1')
	{
		if (*c_num == 0 && (param->map->map_str)[*y - 1][*x] == 'E')
			exit_game(param);
		else if (*c_num != 0 && (param->map->map_str)[*y - 1][*x] == 'E')
			return (not_ended_inexit(x, y, c_num, param));
		if ((param->map->map_str)[*y - 1][*x] == 'C' && *c_num != 0)
			*c_num = *c_num - 1;
		if ((param->map->map_str)[*y][*x] == 'L')
			return (out_exit(x, y, c_num, param));
		*y = *y - 1;
		param->moved_count = param->moved_count + 1;
		ft_printf("move count is %d\n", param->moved_count);
		(param->map->map_str)[*y + 1][*x] = '0';
		(param->map->map_str)[*y][*x] = 'P';
		mlx_put_image_to_window(param->mlx, param->win, \
		param->img_player, (*x) * 32, (*y) * 32);
		mlx_put_image_to_window(param->mlx, param->win, \
		param->img_tile, (*x) * 32, (*y) * 32 + 32);
	}
}

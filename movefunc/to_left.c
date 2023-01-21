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

static	void	show_counter(t_game *param)
{
	char	*str;
	int		wid;
	int		hei;

	wid = param->map->width * 32;
	hei = (param->map->height - 1) * 32;
	str = ft_itoa(param->moved_count);
	mlx_put_image_to_window(param->mlx, param->win, \
	param->white_img, wid, hei);
	mlx_string_put(param->mlx, param->win, wid, hei + 32, 0x00FF0000, str);
	free (str);
}

static	void	not_ended_inexit(int *x, int *y, int *c_num, t_game *param)
{
	ft_printf("You must collect item\n");
	*x = *x - 1;
	param->moved_count = param->moved_count + 1;
	ft_printf("move count is %d\n", param->moved_count);
	show_counter(param);
	(param->map->map_str)[*y][*x + 1] = '0';
	(param->map->map_str)[*y][*x] = 'L';
	mlx_put_image_to_window(param->mlx, param->win, \
	param->p_ongoal, (*x) * 32, (*y) * 32);
	mlx_put_image_to_window(param->mlx, param->win, \
	param->img_tile, (*x) * 32 + 32, (*y) * 32);
}

static	void	out_exit(int *x, int *y, int *c_num, t_game *param)
{
	*x = *x - 1;
	param->moved_count = param->moved_count + 1;
	ft_printf("move count is %d\n", param->moved_count);
	show_counter(param);
	(param->map->map_str)[*y][*x + 1] = 'E';
	(param->map->map_str)[*y][*x] = 'P';
	mlx_put_image_to_window(param->mlx, param->win, \
	param->img_goal, (*x) * 32 + 32, (*y) * 32);
	mlx_put_image_to_window(param->mlx, param->win, \
	param->img_player, (*x) * 32, (*y) * 32);
}

void	to_left(int *x, int *y, int *c_num, t_game *param)
{
	if ((param->map->map_str)[*y][*x - 1] != '1')
	{
		if (*c_num == 0 && (param->map->map_str)[*y][*x - 1] == 'E')
			exit_game(param);
		else if (*c_num != 0 && (param->map->map_str)[*y][*x - 1] == 'E')
			return (not_ended_inexit(x, y, c_num, param));
		if ((param->map->map_str)[*y][*x - 1] == 'C' && *c_num != 0)
			*c_num = *c_num - 1;
		if ((param->map->map_str)[*y][*x] == 'L')
			return (out_exit(x, y, c_num, param));
		*x = *x - 1;
		param->moved_count = param->moved_count + 1;
		ft_printf("move count is %d\n", param->moved_count);
		show_counter(param);
		(param->map->map_str)[*y][*x + 1] = '0';
		(param->map->map_str)[*y][*x] = 'P';
		mlx_put_image_to_window(param->mlx, param->win, \
		param->img_player, (*x) * 32, (*y) * 32);
		mlx_put_image_to_window(param->mlx, param->win, \
		param->img_tile, (*x) * 32 + 32, (*y) * 32);
	}
}

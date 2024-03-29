/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 23:00:44 by satushi           #+#    #+#             */
/*   Updated: 2022/12/15 23:00:44 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	switch_draw_image(char sub, t_game gameinfo, int x, int y)
{
	if (sub == '0')
		mlx_put_image_to_window(gameinfo.mlx, \
		gameinfo.win, gameinfo.img_tile, x, y);
	else if (sub == '1')
		mlx_put_image_to_window(gameinfo.mlx, \
		gameinfo.win, gameinfo.img_wall, x, y);
	else if (sub == 'P')
		mlx_put_image_to_window(gameinfo.mlx, \
		gameinfo.win, gameinfo.img_player, x, y);
	else if (sub == 'C')
		mlx_put_image_to_window(gameinfo.mlx, \
		gameinfo.win, gameinfo.img_key, x, y);
	else if (sub == 'E')
		mlx_put_image_to_window(gameinfo.mlx, \
		gameinfo.win, gameinfo.img_goal, x, y);
	else if (sub == 'L')
		mlx_put_image_to_window(gameinfo.mlx, \
		gameinfo.win, gameinfo.p_ongoal, x, y);
	else
		return ;
}

t_game	draw_map(t_game gameinfo)
{
	int		row;
	int		number;

	row = 0;
	number = 0;
	while (row != gameinfo.map->height)
	{
		while (gameinfo.map->map_str[row][number] != '\0')
		{
			switch_draw_image(gameinfo.map->map_str[row][number], \
			gameinfo, 32 * number, 32 * row);
			number++;
		}
		row++;
		number = 0;
	}
	return (gameinfo);
}

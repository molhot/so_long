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

void put_image(t_game gameinfo, char *filepath, int x, int y)
{
	int		img_w;
	int		img_h;

	img_w = 50;
	img_h = 50;
	gameinfo.img = mlx_xpm_file_to_image(gameinfo.mlx, "../item_image/MiConv.com__ducsfund.xpm", &img_w, &img_h);
	mlx_put_image_to_window(gameinfo.mlx, gameinfo.win, gameinfo.img, x, y);
}

void switch_draw_image(char sub, t_game gameinfo, int x, int y)
{
	if (sub == '0')
		put_image(gameinfo, "../item_image/kusa.xpm", x, y);
	else if (sub == '1')
		put_image(gameinfo, "../item_image/ajisai.xpm", x, y);
	else if (sub == 'P')
		put_image(gameinfo, "../item_image/dog.xpm", x, y);
	else if (sub == 'C')
		put_image(gameinfo, "../item_image/key.xpm", x, y);
	else if (sub == 'E')
		put_image(gameinfo, "../item_image/nankin.xpm", x, y);
}

void draw_map(t_game gameinfo)
{
	char	*map_line;
	size_t	map_height;
	int		row;
	int		number;

	map_height = gameinfo.map->height;
	row = 0;
	number = 0;
	while (row != map_height)
	{
		map_line = gameinfo.map->map_str[row];
		while (map_line[number] != '\0')
		{
			switch_draw_image(map_line[number], 50 * number, 50 * row);
			number++;
		}
		row++;
		number = 0;
	}
}
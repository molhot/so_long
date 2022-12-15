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
	img_h = 50
	gameinfo.img = mlx_xpm_file_to_image(gameinfo.mlx, "../item_image/MiConv.com__ducsfund.xpm", &img_w, &img_h);
	mlx_put_image_to_window(gameinfo.mlx, gameinfo.win, gameinfo.img, x, y)
}

void switch_draw_image(char sub, t_game gameinfo, int x, int y)
{
	if (sub == '0')
		put_image()
	else if (sub == '1')
		printf("1");
	else if (sub == 'P')
		printf("P");
	else if (sub == 'E')
		printf("E");
}

void draw_map(t_game gameinfo)
{
	char	*map_line;
	size_t	map_height;
	int		row;
	int		number;

	height = gameinfo.map->height;
	row = 0;
	number = 0;
	while (row != map_height)
	{
		map_line = gameinfo.map->map_str[row];
		while (map_line[number] != '\0')
		{
			switch_draw_image(map_line[number], 50 * row, 50 * number);
			number++;
		}
		row++;
		number = 0;
	}
}
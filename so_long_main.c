/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:49:19 by satushi           #+#    #+#             */
/*   Updated: 2022/12/14 18:49:19 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void img_info_init(t_game *gameinfo)
{
	int	width;
	int	height;
	t_game **subaddress;

	// (*gameinfo).img_wall = mlx_xpm_file_to_image((*gameinfo).mlx, "item_image/wall.xpm" , &width, &height);
	// (*gameinfo).img_tile = mlx_xpm_file_to_image((*gameinfo).mlx, "item_image/grass.xpm" , &width, &height);
	// (*gameinfo).img_player = mlx_xpm_file_to_image((*gameinfo).mlx, "item_image/tenshi.xpm" , &width, &height);
	// (*gameinfo).img_key = mlx_xpm_file_to_image((*gameinfo).mlx, "item_image/crystal.xpm" , &width, &height);
	// (*gameinfo).img_goal = mlx_xpm_file_to_image((*gameinfo).mlx, "item_image/toride.xpm" , &width, &height);
	subaddress = &gameinfo;
	init_imgtile(subaddress);
	init_imgplayer(subaddress);
	init_imgcollectitem(subaddress);
	init_imggoal(subaddress);
	init_imgwall(subaddress);
}

int main()
{
	t_game	game_all_info;
	int		width;
	int		height;

	game_all_info.map = read_map("map_image/map_image.ber");
	//testmapにmap情報が格納される
	printf("%s\n", "test3");

	game_all_info.mlx = mlx_init();
	//描画の初期化
	printf("%s\n", "test3");

	game_all_info.win = mlx_new_window(game_all_info.mlx, 1920, 1080, "gamingwindow");
	//windowの初期化
	printf("%s\n", "test3");

	img_info_init(&game_all_info);
	printf("%s\n", (char*)game_all_info.img_goal);
	//各種イメージデータの初期化
	// game_all_info.img_wall = mlx_xpm_file_to_image(game_all_info.mlx, "item_image/wall.xpm" , &width, &height);
	// game_all_info.img_tile = mlx_xpm_file_to_image(game_all_info.mlx, "item_image/grass.xpm" , &width, &height);
	// game_all_info.img_player = mlx_xpm_file_to_image(game_all_info.mlx, "item_image/tenshi.xpm" , &width, &height);
	// game_all_info.img_key = mlx_xpm_file_to_image(game_all_info.mlx, "item_image/crystal.xpm" , &width, &height);
	//game_all_info.img_goal = mlx_xpm_file_to_image(game_all_info.mlx, "item_image/toride.xpm" , &width, &height);
	printf("%s\n", "test3");


	printf("%s\n", "test3");
	//mlx_put_image_to_window(game_all_info.mlx, game_all_info.win, game_all_info.img_goal, 32, 32);

	draw_map(game_all_info);
	//mapデータの書き込み
	//printf("%s\n", "test4");

	mlx_loop(game_all_info.mlx);
}
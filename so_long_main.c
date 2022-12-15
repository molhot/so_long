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

int main()
{
	t_game	game_all_info;
	t_img	main_img;

	game_all_info.map = read_map("../map_image/map_image.ber");
	//testmapにmap情報が格納される

	game_all_info.mlx = mlx_init();
	//描画の初期化
	game_all_info.win = mlx_new_window(game_all_info.mlx, 1920, 1080, "gamingwindow");
	//windowの初期化
	mlx_hook(game_all_info.win, 1L<<0, close, &game_all_info);
	main_img.img = mlx_new_image(game_all_info.mlx, 1920, 1080);
	main_img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	write_map()
}
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

	game_all_info.map = read_map("../map_image/map_image.ber");
	//testmapにmap情報が格納される

	game_all_info.mlx = mlx_init();
	//描画の初期化
	game_all_info.win = mlx_new_window(game_all_info.mlx, 1920, 1080, "gamingwindow");
	//windowの初期化
	
	game_all_info.map = read_map(game_all_info.map);
	//mapデータの読み込み

	
	//mapデータの書き込み
}
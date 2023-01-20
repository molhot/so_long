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

void	img_info_init(t_game *gameinfo)
{
	int		width;
	int		height;
	t_game	**subaddress;

	subaddress = &gameinfo;
	init_imgtile(subaddress);
	init_imgplayer(subaddress);
	init_imgcollectitem(subaddress);
	init_imggoal(subaddress);
	init_imgwall(subaddress);
	init_img_pontower(subaddress);
}

int	key_press(int keycode, t_game *param)
{
	if (keycode == 65363 || keycode == 100)
	{
		to_right(&(param->player_x), &(param->player_y), \
		&(param->collectitem_num), param);
	}
	if (keycode == 65362 || keycode == 122)
	{
		to_up(&(param->player_x), &(param->player_y), \
		&(param->collectitem_num), param);
	}
	if (keycode == 65361 || keycode == 113)
	{
		to_left(&(param->player_x), &(param->player_y), \
		&(param->collectitem_num), param);
	}
	if (keycode == 65364 || keycode == 115)
	{
		to_down(&(param->player_x), &(param->player_y), \
		&(param->collectitem_num), param);
	}
	if (keycode == 65307)
		exit_game(param);
}

int	re_make(t_game *param)
{
	draw_map(*param);
}

void	obtain_psinfo(int *x, int *y, t_map *map)
{
	int	width_c;
	int	height_c;

	width_c = 0;
	height_c = 0;
	while (height_c != map->height)
	{
		while (width_c != map->width)
		{
			if ((*map).map_str[height_c][width_c] == 'P')
			{
				*x = width_c;
				*y = height_c;
				return ;
			}
			width_c++;
		}
		height_c++;
		width_c = 0;
	}
}

int	main(int argc, char **argv)
{
	t_game	game_all_info;

	if (arg_check(argc, argv) == false)
		return (1);
	game_all_info.map = read_map(argv[1]);
	if (game_all_info.map->map_str[0] == NULL \
	|| false == map_basiccheck(game_all_info.map->map_str))
		exit_game_error(&game_all_info);
	free_map(&game_all_info);
	game_all_info.map = read_map(argv[1]);
	game_all_info.collectitem_num = \
	obtain_correctitem(game_all_info.map->map_str);
	obtain_psinfo(&(game_all_info.player_x), \
	&(game_all_info.player_y), game_all_info.map);
	game_all_info.moved_count = 0;
	game_all_info.mlx = mlx_init();
	game_all_info.win = mlx_new_window(game_all_info.mlx, \
	game_all_info.map->width * 32, \
	game_all_info.map->height * 32, "gamingwindow");
	img_info_init(&game_all_info);
	mlx_hook(game_all_info.win, 2, 1L << 0, key_press, &game_all_info);
	mlx_hook(game_all_info.win, 33, 1L << 17, exit_game, &game_all_info);
	mlx_hook(game_all_info.win, 9, 1L << 21, re_make, &game_all_info);
	game_all_info = draw_map(game_all_info);
	mlx_loop(game_all_info.mlx);
}

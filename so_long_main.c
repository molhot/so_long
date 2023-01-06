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
}

int	key_press(int keycode, t_game *param)
{
	if (keycode == 65363 || keycode == 100)
	{
		printf("pushed keycode is right\n");
		to_right(&(param->player_x), &(param->player_y), \
		&(param->collectitem_num), param);
	}
	if (keycode == 65362 || keycode == 122)
	{
		printf("pushed keycode is up\n");
		to_up(&(param->player_x), &(param->player_y), \
		&(param->collectitem_num), param);
	}
	if (keycode == 65361 || keycode == 113)
	{
		printf("pushed keycode is left\n");
		to_left(&(param->player_x), &(param->player_y), \
		&(param->collectitem_num), param);
	}
	if (keycode == 65364 || keycode == 115)
	{
		printf("pushed keycode is down\n");
		to_down(&(param->player_x), &(param->player_y), \
		&(param->collectitem_num), param);
	}
}

int	re_make(t_game *param)
{
	draw_map(*param);
}

// int	exit_game_error(t_game *game_all_info)
// {
// 	int	i;

// 	i = 0;
// 	while (((*game_all_info).map->map_str)[i] != NULL)
// 	{
// 		free(((*game_all_info).map->map_str)[i]);
// 		i++;
// 	}
// 	free(((*game_all_info).map->map_str)[i]);
// 	free((*game_all_info).map->map_str);
// 	perror("this map is not corrective");
// 	free((*game_all_info).map);
// 	exit(0);
// }

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

// void	free_map(t_game *game_all_info)
// {
// 	int	i;

// 	i = 0;
// 	while ((game_all_info->map->map_str)[i] != NULL)
// 	{
// 		free((game_all_info->map->map_str)[i]);
// 		i++;
// 	}
// 	free((game_all_info->map->map_str)[i]);
// 	free(game_all_info->map->map_str);
// 	free(game_all_info->map);
// }

int	main(void)
{
	t_game	game_all_info;

	game_all_info.map = read_map("map_image/map_image.ber");
	if (false == map_basiccheck(game_all_info.map->map_str))
		exit_game_error(&game_all_info);
	free_map(&game_all_info);
	game_all_info.map = read_map("map_image/map_image.ber");
	game_all_info.collectitem_num = \
	obtain_correctitem(game_all_info.map->map_str);
	obtain_psinfo(&(game_all_info.player_x), \
	&(game_all_info.player_y), game_all_info.map);
	game_all_info.moved_count = 0;
	game_all_info.mlx = mlx_init();
	game_all_info.win = mlx_new_window(game_all_info.mlx, \
	800, 600, "gamingwindow");
	img_info_init(&game_all_info);
	mlx_hook(game_all_info.win, 2, 1L << 0, key_press, &game_all_info);
	mlx_hook(game_all_info.win, 33, 1L << 17, exit_game, &game_all_info);
	mlx_hook(game_all_info.win, 9, 1L << 21, re_make, &game_all_info);
	game_all_info = draw_map(game_all_info);
	mlx_loop(game_all_info.mlx);
}

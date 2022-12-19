/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:01:41 by satushi           #+#    #+#             */
/*   Updated: 2022/12/18 21:01:41 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

void init_imgwall(t_game gameinfo, char *filepath)
{
	int	width;
	int	height;

	gameinfo.img_wall = mlx_xpm_file_to_image(vars.mlx,"item_image/wall.xpm" , &width, &height);
}

void init_imgtile(t_game gameinfo, char *filepath)
{
	int	width;
	int	height;

	gameinfo.img_tile = mlx_xpm_file_to_image(vars.mlx,"item_image/grass.xpm" , &width, &height);
}

void init_imgplayer(t_game gameinfo, char *filepath)
{
	int	width;
	int	height;

	gameinfo.img_tile = mlx_xpm_file_to_image(vars.mlx,"item_image/tenshi.xpm" , &width, &height);
}

void init_imgcollectitem(t_game gameinfo, char *filepath)
{
	int	width;
	int	height;

	gameinfo.img_tile = mlx_xpm_file_to_image(vars.mlx,"item_image/crystal.xpm" , &width, &height);
}

void init_imggoal(t_game gameinfo, char *filepath)
{
	int	width;
	int	height;

	gameinfo.img_tile = mlx_xpm_file_to_image(vars.mlx,"item_image/toride.xpm" , &width, &height);
}
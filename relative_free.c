/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relative_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:01:17 by satushi           #+#    #+#             */
/*   Updated: 2023/01/06 10:04:30 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_game *game_all_info)
{
	int	i;

	i = 0;
	while (((*game_all_info).map->map_str)[i] != NULL)
	{
		free(((*game_all_info).map->map_str)[i]);
		i++;
	}
	free(((*game_all_info).map->map_str)[i]);
	free((*game_all_info).map->map_str);
	free((*game_all_info).map);
	mlx_destroy_window((*game_all_info).mlx, (*game_all_info).win);
	exit(0);
}

void	free_map(t_game *game_all_info)
{
	int	i;

	i = 0;
	while ((game_all_info->map->map_str)[i] != NULL)
	{
		free((game_all_info->map->map_str)[i]);
		i++;
	}
	free((game_all_info->map->map_str)[i]);
	free(game_all_info->map->map_str);
	free(game_all_info->map);
}

int	exit_game_error(t_game *game_all_info)
{
	int	i;

	i = 0;
	while (((*game_all_info).map->map_str)[i] != NULL)
	{
		free(((*game_all_info).map->map_str)[i]);
		i++;
	}
	free(((*game_all_info).map->map_str)[i]);
	free((*game_all_info).map->map_str);
	perror("this map is not corrective");
	free((*game_all_info).map);
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_mapinfo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:23:09 by satushi           #+#    #+#             */
/*   Updated: 2022/12/14 23:23:09 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static t_map *obtain_map_info(char *map, t_map *mapinfo)
{
	char	*line;
	int		height;
	int		width;
	int		fd;

	fd = open(map, O_RDONLY);
	line = ft_strdup("");
	height = 0;
	while (s != NULL)
	{
		line = get_next_line(fd);
		if (height == 0)
			width = ft_strlen(line);
		height++;
		free(line);
	}
	mapinfo->height = height;
	mapinfo->width = width;
	mapinfo->map_str = ft_strdup("");
	return mapinfo;
}

int **read_map(char *map)
{
	t_map *map_info;

	map_info = (map_info *)malloc(sizeof(map_info) * 1);
	map_info = obtain_map_info(map, map_info);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_mapinfo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:23:09 by satushi           #+#    #+#             */
/*   Updated: 2022/12/22 00:02:16 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	gnl_line(char *line)
{
	int	line_w;

	line_w = 0;
	while (line[line_w] == '1')
		line_w++;
	line_w--;
	return line_w;
}

static t_map *obtain_map_info(char *map, t_map *mapinfo)
{
	char	*line;
	int		height;
	int		width;
	int		fd;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	height = 0;
	while (line != NULL)
	{
		if (height == 0)
			width = gnl_line(line);
		line = get_next_line(fd);
		height++;
	}
	mapinfo->height = height;
	mapinfo->width = width;
	printf("mapinfo's width is %d\n", mapinfo->width);
	return (mapinfo);
}

t_map *read_map(char *map)
{
	t_map	*map_info;
	size_t	i;
	int		fd;
	char	*line;

	map_info = (t_map *)malloc(sizeof(t_map) * 1);
	map_info = obtain_map_info(map, map_info);
	map_info->map_str = (char **)malloc(sizeof(char *) * (map_info->height + 1));
	i = 0;
	fd = open(map, O_RDONLY);
	line = ft_strdup("");
	while (i != map_info->height)
	{
		line = get_next_line(fd);
		(map_info->map_str)[i] = ft_strdup(line);
		i++;
	}
	(map_info->map_str[i]) = NULL;
	printf("first mapinfo's height is %d\n", map_info->height);
	printf("first mapinfo's width is %d\n", map_info->width);
	return (map_info);
}

/*
int main()
{
	t_map *testmap;
	int i;

	testmap = read_map("../map_image/map_image.ber");
	i = 0;
	while (i != testmap->height - 1)
	{
		printf("%s", testmap->map_str[i]);
		i++;
	}
	return (0);
}
*/

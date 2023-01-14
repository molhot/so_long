/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_mapinfo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:23:09 by satushi           #+#    #+#             */
/*   Updated: 2023/01/06 10:07:00 by satushi          ###   ########.fr       */
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
	return (line_w);
}

static t_map	*obtain_map_info(char *map, t_map *mapinfo)
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
		free(line);
		line = get_next_line(fd);
		height++;
	}
	mapinfo->height = height;
	mapinfo->width = width;
	return (mapinfo);
}

char	*obtain_line_memory(char *subject, char *sub_line)
{
	size_t	line_length;
	size_t	position;

	line_length = ft_strlen_withn(sub_line);
	position = 0;
	subject = (char *)malloc(sizeof(char) * (line_length + 1));
	position = 0;
	while (position != line_length)
	{
		subject[position] = sub_line[position];
		position++;
	}
	subject[position] = '\0';
	return (subject);
}

t_map	*read_map(char *map)
{
	t_map	*map_info;
	size_t	i;
	int		fd;
	char	*line;

	map_info = (t_map *)malloc(sizeof(t_map) * 1);
	map_info = obtain_map_info(map, map_info);
	map_info->map_str = (char **)malloc(sizeof(char *) \
	* (map_info->height + 1));
	i = 0;
	fd = open(map, O_RDONLY);
	while (i != map_info->height)
	{
		line = get_next_line(fd);
		map_info->map_str[i] = obtain_line_memory((map_info->map_str)[i], line);
		free(line);
		i++;
	}
	(map_info->map_str[i]) = NULL;
	return (map_info);
}

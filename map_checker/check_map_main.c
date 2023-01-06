/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:13:40 by satushi           #+#    #+#             */
/*   Updated: 2023/01/06 10:09:23 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	map_surround_check_helper1(char *line)
{
	size_t	position;

	position = 0;
	while (line[position] != '\0' && line[position] != '\n')
	{
		if (line[position] != '1')
			return (false);
		position++;
	}
	return (true);
}

bool	map_surround_check_helper2(char *line, size_t rowmax)
{
	if (line[0] != '1' || line[rowmax - 1] != '1')
		return (false);
	return (true);
}

static	bool	map_surroundcheck(char **map, size_t high, size_t row)
{
	bool	judge;
	size_t	map_high;

	judge = true;
	map_high = 0;
	while (map_high != high)
	{
		if (map_high == 0 || map_high == high)
			judge = map_surround_check_helper1(map[map_high]);
		else
			judge = map_surround_check_helper2(map[map_high], row);
		if (judge == false)
			return (false);
		map_high++;
	}
	return (true);
}

bool	map_basiccheck(char **mapinfo)
{
	size_t	map_position;
	size_t	position;
	size_t	map_high;
	size_t	map_row;

	map_position = 0;
	position = 0;
	while (mapinfo[map_position] != NULL)
		map_position++;
	if (map_rowcheck(mapinfo) != true)
		return (false);
	if (mandatory_mapcheck(mapinfo) != true)
		return (false);
	map_row = ft_strlen_withn(mapinfo[0]);
	map_high = map_position;
	if (map_surroundcheck(mapinfo, map_high, map_row) != true)
		return (false);
	if (fill_check(mapinfo, map_high) != true)
		return (false);
	return (true);
}

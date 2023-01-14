/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 21:16:18 by satushi           #+#    #+#             */
/*   Updated: 2023/01/06 10:08:32 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	**fill_repeat(char **map_copy, int high, int row)
{
	if (map_copy[high][row] != 'P')
		map_copy[high][row] = 'X';
	if (map_copy[high + 1][row] != '1' && map_copy[high + 1][row] != 'X')
		fill_repeat(map_copy, high + 1, row);
	if (map_copy[high - 1][row] != '1' && map_copy[high - 1][row] != 'X')
		fill_repeat(map_copy, high - 1, row);
	if (map_copy[high][row + 1] != '1' && map_copy[high][row + 1] != 'X')
		fill_repeat(map_copy, high, row + 1);
	if (map_copy[high][row - 1] != '1' && map_copy[high][row - 1] != 'X')
		fill_repeat(map_copy, high, row - 1);
	return (map_copy);
}

static	bool	playable_or_not(char **map)
{
	size_t	map_high;

	map_high = 0;
	while (map[map_high] != NULL)
	{
		if (ft_strchr(map[map_high], 'E') != NULL || \
		ft_strchr(map[map_high], 'C') != NULL)
			return (false);
		map_high++;
	}
	return (true);
}

bool	fill_check(char **mapinfo, int position)
{
	int		row;
	int		high;
	bool	judge;

	row = 0;
	high = 0;
	while (high != position)
	{
		while (mapinfo[high][row] != '\n' && mapinfo[high][row] != '\0')
		{
			if (mapinfo[high][row] == 'P')
				mapinfo = fill_repeat(mapinfo, high, row);
			row ++;
		}
		row = 0;
		high++;
	}
	judge = playable_or_not(mapinfo);
	return (judge);
}

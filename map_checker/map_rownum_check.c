/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rownum_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:31:15 by satushi           #+#    #+#             */
/*   Updated: 2023/01/04 10:14:52 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	map_rowcheck(char **mapinfo)
{
	size_t	position;
	size_t	befor_row;
	size_t	row;

	position = 0;
	befor_row = ft_strlen_withn(mapinfo[position]);
	while (mapinfo[position + 1] != NULL)
	{
		position++;
		row = ft_strlen_withn(mapinfo[position]);
		if (row != befor_row)
			return (false);
		befor_row = row;
	}
	return (true);
}

bool	map_container_check(char **mapinfo, int max_row)
{
	size_t	high;
	size_t	row;

	high = 0;
	row = 0;
	while (mapinfo[high] != NULL)
	{
		while (row != max_row)
		{
			if (mapinfo[high][row] != 'C' \
			&& mapinfo[high][row] != 'P' \
			&& mapinfo[high][row] != 'E' \
			&& mapinfo[high][row] != '1' \
			&& mapinfo[high][row] != '0')
				return (false);
			row++;
		}
		high++;
		row = 0;
	}
	return (true);
}

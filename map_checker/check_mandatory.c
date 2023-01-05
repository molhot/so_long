/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mandatory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:51:22 by satushi           #+#    #+#             */
/*   Updated: 2023/01/04 09:16:24 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	size_t	p_counter(char **map)
{
	size_t	p_counter;
	size_t	map_high;
	size_t	map_row;

	map_high = 0;
	map_row = 0;
	p_counter = 0;
	while (map[map_high] != NULL)
	{
		while (map[map_high][map_row] != '\0')
		{
			if (map[map_high][map_row] == 'P')
				p_counter++;
			map_row++;
		}
		map_row = 0;
		map_high++;
	}
	return (p_counter);
}

static	size_t	e_counter(char **map)
{
	size_t	e_counter;
	size_t	map_high;
	size_t	map_row;

	map_high = 0;
	map_row = 0;
	e_counter = 0;
	while (map[map_high] != NULL)
	{
		while (map[map_high][map_row] != '\0')
		{
			if (map[map_high][map_row] == 'E')
				e_counter++;
			map_row++;
		}
		map_row = 0;
		map_high++;
	}
	return (e_counter);
}

static	size_t	c_counter(char **map)
{
	size_t	c_counter;
	size_t	map_high;
	size_t	map_row;

	map_high = 0;
	map_row = 0;
	c_counter = 0;
	while (map[map_high] != NULL)
	{
		while (map[map_high][map_row] != '\0')
		{
			if (map[map_high][map_row] == 'C')
				c_counter++;
			map_row++;
		}
		map_row = 0;
		map_high++;
	}
	return (c_counter);
}

bool	mandatory_mapcheck(char **map)
{
	size_t	p;
	size_t	e;
	size_t	c;
	int		map_highposition;
	size_t	rowposition;

	ft_printf("p %d\n", p_counter(map));
	ft_printf("e %d\n", e_counter(map));
	ft_printf("c %d\n", c_counter(map));
	if (p_counter(map) == 1 && e_counter(map) > 0 && c_counter(map) > 0)
		return (true);
	return (false);
}

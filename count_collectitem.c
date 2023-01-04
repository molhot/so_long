/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_collectitem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:35:47 by satushi           #+#    #+#             */
/*   Updated: 2023/01/03 23:33:00 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	obtain_correctitem(char **map)
{
	int	width;
	int	height;
	int	collectitem_num;

	width = 0;
	height = 0;
	collectitem_num = 0;
	while (map[height] != NULL)
	{
		while (map[height][width] != '\0')
		{
			if (map[height][width] == 'C')
				collectitem_num++;
			width++;
		}
		width = 0;
		height++;
	}
	return (collectitem_num);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chanum_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:20:01 by satushi           #+#    #+#             */
/*   Updated: 2023/01/03 11:20:01 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

static void char_increment(char **map, int high, size_t row, size_t *P, size_t *E, size_t *C)
{
	while (map[map_highposition++] != NULL)
    {
        while (map[map_highposition][rowposition] != '\0')
        {
            if (map[map_highposition][rowposition] == 'P')
                p++;
            else if (map[map_highposition][rowposition] == 'E')
                e++;
            else if (map[map_highposition][rowposition] == 'C')
                c++;
            rowposition++;
        }
        rowposition = 0;
    }
}

bool mandatory_mapcheck(char **map)
{
    size_t  p;
    size_t  e;
    size_t  c;
    int  	map_highposition;
    size_t  rowposition;

    p = 0;
    e = 0;
    c = 0;
    map_highposition = -1;
    rowposition = 0; 
	char_increment(map, map_highposition, rowposition, &p, &e, &c);
    if (p == 1 && e > 0 && c > 0)
        return (true);
    return (false);
}
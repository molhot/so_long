/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mandatory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:51:22 by satushi           #+#    #+#             */
/*   Updated: 2023/01/03 20:51:22 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

static void char_increment(char **map, size_t high, size_t row, size_t *P, size_t *E, size_t *C)
{
    while (map[high] != NULL)
    {
        while (map[high][row] != '\0')
        {
          if (map[high][row] == 'P')
                *P = *P + 1;
            else if (map[high][row] == 'E')
                *E = *E + 1;
            else if (map[high][row] == 'C')
                *C = *C + 1;
            row++;
        }
        row = 0;
        high++;
    }
}

bool mandatory_mapcheck(char **map)
{
    size_t  p;
    size_t  e;
    size_t  c;
    int      map_highposition;
    size_t  rowposition;

    p = 0;
    e = 0;
    c = 0;
    map_highposition = 0;
    rowposition = 0; 
    char_increment(map, map_highposition, rowposition, &p, &e, &c);
    if (p == 1 && e > 0 && c > 0)
        return (true);
    return (false);
} 
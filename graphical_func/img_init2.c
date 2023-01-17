/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:31:53 by satushi           #+#    #+#             */
/*   Updated: 2023/01/17 22:41:53 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_img_pontower(t_game **gameinfo)
{
	int	width;
	int	height;

	(**gameinfo).p_ongoal = mlx_xpm_file_to_image((**gameinfo).mlx, \
	"item_image/p_ontower.xpm", &width, &height);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:14:18 by satushi           #+#    #+#             */
/*   Updated: 2023/01/19 23:19:13 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	arg_check(int argc, char **args)
{
	size_t	s_l;

	if (argc != 2)
		return (false);
	s_l = ft_strlen(args[1]);
	if (args[1][s_l - 1] != 'r' || args[1][s_l - 2] != 'e' || \
	args[1][s_l - 3] != 'b' || args[1][s_l - 4] != '.')
		return (false);
	return (true);
}
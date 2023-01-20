/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:14:18 by satushi           #+#    #+#             */
/*   Updated: 2023/01/20 23:53:32 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	arg_check(int argc, char **args)
{
	size_t	s_l;

	if (argc != 2)
	{
		ft_printf("your args is wrong\n");
		return (false);
	}
	s_l = ft_strlen(args[1]);
	if (args[1][s_l - 1] != 'r' || args[1][s_l - 2] != 'e' || \
	args[1][s_l - 3] != 'b' || args[1][s_l - 4] != '.')
	{
		ft_printf("file is must end with .ber\n");
		return (false);
	}
	return (true);
}

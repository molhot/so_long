/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 07:52:49 by satushi           #+#    #+#             */
/*   Updated: 2023/01/06 07:52:49 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_putchar(char inputchar_num)
{
	return (write(1, &inputchar_num, 1));
}

size_t	ft_putchar_string(char *sub_string)
{
	size_t	len;

	if (sub_string == NULL)
		return (ft_putchar_string("(null)"));
	len = 0;
	while (sub_string[len] != '\0')
		len = len + 1;
	return (write(1, sub_string, len));
}

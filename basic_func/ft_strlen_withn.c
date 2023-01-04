/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_withn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:29:51 by satushi           #+#    #+#             */
/*   Updated: 2023/01/03 23:47:45 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlen_withn(const char (*string_row))
{
	size_t	stringlen;

	stringlen = 0;
	while (string_row[stringlen] != '\0' && string_row[stringlen] != '\n')
		stringlen++;
	return (stringlen);
}

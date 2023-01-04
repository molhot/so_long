/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:02:14 by satushi           #+#    #+#             */
/*   Updated: 2022/12/14 20:02:14 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strchr(const char (*s), int c)
{
	size_t	num;

	if (s == NULL)
		return (NULL);
	num = 0;
	while (s[num] != '\0')
	{
		if ((unsigned char)s[num] == (unsigned char)c)
			return ((char *)s + num);
		num = num + 1;
	}
	return (NULL);
}

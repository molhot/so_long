/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:02:41 by satushi           #+#    #+#             */
/*   Updated: 2022/12/14 20:02:41 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*src_sub;

	len = ft_strlen(s);
	src_sub = (char *)malloc(sizeof(char) * (len + 1));
	if (src_sub == NULL)
		return (NULL);
	while ((*s) != '\0')
	{
		*src_sub = *s;
		s = s + 1;
		src_sub = src_sub + 1;
	}
	*src_sub = '\0';
	src_sub = src_sub - len;
	return (src_sub);
}

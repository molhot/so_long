/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:03:43 by satushi           #+#    #+#             */
/*   Updated: 2022/12/14 20:03:43 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	char	*input_char(const char *insert, char *inserted)
{
	while ((*insert) != '\0')
	{
		*inserted = *insert;
		insert = insert + 1;
		inserted = inserted + 1;
	}
	return (inserted);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len;
	char		*dust;
	char		*dust_first;

	if ((s1 == NULL) && (s2 == NULL))
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	dust = (char *)malloc(sizeof(char) * (len + 1));
	if (!(dust))
		return (NULL);
	dust_first = dust;
	dust = input_char(s1, dust);
	dust = input_char(s2, dust);
	*dust = '\0';
	free((char *)s1);
	return (dust_first);
}
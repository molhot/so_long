/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:53:41 by satushi           #+#    #+#             */
/*   Updated: 2022/12/14 18:53:41 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <unistd.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

typedef struct	s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		**map;
}	t_game;

typedef struct	s_map
{
	int width;
	int height;
	char **map_str;
}	t_map;

char	*ft_strchr(const char (*s), int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char (*string_row));
char	*ft_strdup(const char *s1);
void	ft_bzero(void *str, size_t n);
char	*get_next_line(int fd_num);
char	*ft_save_gnl(int fd, char *save);
char	*ft_prepareline(char *save);
char	*ft_preparenextline(char *save_in_n);
size_t	ft_strlcat(char *dst, char *src, size_t final_dst_size);
size_t	ft_strlcpy(char *dst, const char *src, size_t cpysize);

#endif
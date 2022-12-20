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
# include "minilibx-linux/mlx.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

typedef struct	s_map
{
	int width;
	int height;
	char **map_str;
}	t_map;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_key;
	void	*img_player;
	void	*img_goal;
	void	*img_tile;
	t_map	*map;
}	t_game;

char	*ft_strchr(const char (*s), int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char (*string_row));
char	*ft_strdup(const char *s1);
void	ft_bzero(void *str, size_t n);
char	*get_next_line(int fd_num);
char	*ft_save_gnl(int fd, char *save);
char	*ft_prepareline(char *save);
char	*ft_preparenextline(char *save_in_n);
size_t	ft_strlcat(char *dst, const char *src, size_t final_dst_size);
size_t	ft_strlcpy(char *dst, const char *src, size_t cpysize);
char	*get_next_line(int fd_num);
void	ft_bzero(void *str, size_t n);
void	draw_map(t_game gameinfo);
void	init_imgwall(t_game **gameinfo);
void	init_imgtile(t_game **gameinfo);
void	init_imgplayer(t_game **gameinfo);
void	init_imgcollectitem(t_game **gameinfo);
void	init_imggoal(t_game **gameinfo);
t_map	*read_map(char *map);

#endif
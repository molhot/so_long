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
# include <stdbool.h>
# include "minilibx-linux/mlx.h"
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_map
{
	int		width;
	int		height;
	char	**map_str;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_key;
	void	*img_player;
	void	*img_goal;
	void	*img_tile;
	void	*white_img;
	void	*p_ongoal;
	int		player_x;
	int		player_y;
	int		collectitem_num;
	int		moved_count;
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
t_game	draw_map(t_game gameinfo);
void	init_imgwall(t_game **gameinfo);
void	init_imgtile(t_game **gameinfo);
void	init_imgplayer(t_game **gameinfo);
void	init_imgcollectitem(t_game **gameinfo);
void	init_imggoal(t_game **gameinfo);
void	init_img_pontower(t_game **gameinfo);
t_map	*read_map(char *map);
void	to_right(int *x, int *y, int *counter, t_game *param);
void	to_up(int *x, int *y, int *counter, t_game *param);
void	to_left(int *x, int *y, int *counter, t_game *param);
void	to_down(int *x, int *y, int *counter, t_game *param);
int		obtain_correctitem(char **map);
bool	map_rowcheck(char **mapinfo);
size_t	ft_strlen_withn(const char (*string_row));
bool	mandatory_mapcheck(char **map);
bool	map_basiccheck(char	**mapinfo);
bool	fill_check(char	**mapinfo, int position);
char	*obtain_line_memory(char *subject, char *sub_line);
int		ft_printf(const char *fmt_or_nch, ...);
size_t	ft_putchar(char inputchar_num);
size_t	ft_putchar_string(char *sub_string);
size_t	inputnbr(long long subject, char *src);
size_t	ft_putnum_to_hexia(long long num, char *basestring);
size_t	ft_putaddr_to_hexia(unsigned long long num, char *basestring);
int		exit_game(t_game *game_all_info);
void	free_map(t_game *game_all_info);
int		exit_game(t_game *game_all_info);
int		exit_game_error(t_game *game_all_info);
bool	arg_check(int argc, char **args);
bool	map_container_check(char **mapinfo, int max_row);
char	*ft_itoa(int n);
void	init_img_white(t_game **gameinfo);

#endif
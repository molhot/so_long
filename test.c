#include "minilibx-linux/mlx.h"
# include<stdio.h>

#define MLX_SYNC_IMAGE_WRITABLE		(int)1
#define MLX_SYNC_WIN_FLUSH_CMD		(int)2
#define MLX_SYNC_WIN_CMD_COMPLETED	(int)3

typedef struct s_data{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
}t_data;

typedef struct s_vcars{
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_tile;
	int		img_width;
	int		img_height;
}	t_vars;

// void move_up(t_vars *vars)
// {
// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->img_height , vars->img_width);
// 	vars->img_height = vars->img_height - 50;
// 	vars->img_width = vars->img_width - 50;
// }

void move_down()
{

}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;
	
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int render_nextframe(t_data *any)
{
	int i = 500;
	int j = 500;

	my_mlx_pixel_put(any, i, j, 0x00FF0000);
	return 0;
}

// int key_hook(int keycode, t_vars *vars)
// {
// 	printf("%d\n", keycode);
// 	if (keycode == 65362)
// 	{
// 		printf("move up is now on func\n");
// 		move_up(vars);
// 	}
// 	return (0);
// }

int close(unsigned long long code, t_vars *vars)
{
	printf("%llu\n", code);
	if (code == 65307)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int exposer(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int main(void)
{
	t_data	img;
	t_vars vars;

	void *mlx;
	void *imimg;
	void *wallimg;
	void *tile;
	void *playerimg;
	char *relative_path = "item_image/daphnia.xpm";
	int imimg_width = 30;
	int imimg_height = 30;
	int map[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	int map_b_w = 0;
	int map_b_h = 0;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "HEY WHAT THE PURODUCTION!");
	mlx_hook(vars.win, 17, 1L<<0, close, &vars);
	//img.img = mlx_new_image(vars.mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// imimg = mlx_xpm_file_to_image(vars.mlx, relative_path, &imimg_width, &imimg_height);
	// playerimg = mlx_xpm_file_to_image(vars.mlx, "item_image/ajisai.xpm", &imimg_width, &imimg_height);
	// vars.img = playerimg;
	// vars.img_height = 200;
	// vars.img_width = 300;
	//mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
	// int i = 0;
	// int j = 0;
	int width;
	int height;
	wallimg = mlx_xpm_file_to_image(vars.mlx,"item_image/grass.xpm" , &width, &height);
	//tile = mlx_xpm_file_to_image(vars.mlx,"item_image/grass.xpm" , &imimg_width, &imimg_height);
	vars.img_wall = wallimg;
	vars.img_tile = tile;
	while (map_b_h != 10)
	{
		while (map_b_w != 10)
		{
			printf("%d %d > height width\n", map_b_h, map_b_w);
			if (map[map_b_h][map_b_w] == 0 || map[map_b_h][map_b_w] == 1)
				mlx_put_image_to_window(vars.mlx, vars.win, vars.img_wall, width * map_b_w, height * map_b_h);
			map_b_w = map_b_w + 1;
		}
		map_b_w = 0;
		map_b_h = map_b_h + 1;
	}
	mlx_loop(vars.mlx);
}
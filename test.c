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
	void *mlx;
	void *win;
}	t_vars;

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
	char *relative_path = "../item_image/kusa.xpm";
	int imimg_width = 500;
	int imimg_height = 500;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "HEY WHAT THE PURODUCTION!");
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_hook(vars.win, 12, 1L<<0, close, &vars);
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	imimg = mlx_xpm_file_to_image(vars.mlx, relative_path, &imimg_width, &imimg_height);
	mlx_put_image_to_window(vars.mlx, vars.win, imimg, 0 , 0);
	mlx_put_image_to_window(vars.mlx, vars.win, imimg, 100 , 100);
	mlx_put_image_to_window(vars.mlx, vars.win, imimg, 200 , 200);
	mlx_put_image_to_window(vars.mlx, vars.win, imimg, 300 , 300);
	mlx_loop(vars.mlx);
}
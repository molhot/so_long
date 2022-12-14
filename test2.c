#define  TILE_SIZE 32

typedef struct s_img
{
	void *img;
	int *data;
	int size_l;
	int bpp;
	int endian;
} t_img;

typedef struct s_game
{
	void *mlx;
	void *win;
	t_img img;
	int map[11][15];
} t_game;

int close(unsigned long long code, t_game *vars)
{
	printf("%llu\n", code);
	if (code == 65307)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

void game_init(t_game *game)
{
	int map[11][15] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	memcpy(game->map, map, sizeof(int)*11*15);
}

void window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->win, game->img.img, 0, 0);//??
}

void img_init(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, 15*30, 11*30);
	game->img.data = mlx_get_data_addr(game->img.img, &game->img.bpp, &game->img.size_l, &game->img.endian);
}

int main()
{
	t_game game;

	game_init(&game);
	window_init(&game);
	img_init(&game);

	mlx_hook(game.win, 2, 1L<<0, close, &game);

	
}
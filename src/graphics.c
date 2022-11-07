#include "../so_long.h"

void	place_player(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx,
		game->win, game->player.player_img, width * TILE_SIZE, height * TILE_SIZE);
	game->player.p_pos_y = height;	
	game->player.p_pos_x = width;
}

void	add_img(t_game *game)
{
	game->empty_img = mlx_xpm_file_to_image(game->mlx,
			"img/empty.xpm", &game->img_size, &game->img_size);
	game->wall_img = mlx_xpm_file_to_image(game->mlx,
			"img/wall.xpm", &game->img_size, &game->img_size);
	game->player.player_img = mlx_xpm_file_to_image(game->mlx,
			"img/player.xpm", &game->img_size, &game->img_size);
	game->exit_img = mlx_xpm_file_to_image(game->mlx,
			"img/exit.xpm", &game->img_size, &game->img_size);
	game->collect_img = mlx_xpm_file_to_image(game->mlx,
			"img/item.xpm", &game->img_size, &game->img_size);
	game->enemy_img = mlx_xpm_file_to_image(game->mlx, 
			"img/ghost.xpm", &game->img_size, &game->img_size);
}

static void	draw_text(t_game game)
{
	char	*str;

	str = ft_itoa(game.moves_count);
		mlx_string_put(game.mlx, game.win,
			game.win_width * TILE_SIZE + TILE_SIZE / 3,
			TILE_SIZE,
			15921152, str);
	free(str);
}

void	render(t_game *game)
{
	int	height;
	int	width;

	mlx_clear_window(game->mlx, game->win);
	height = 0;
	while (height < game->win_height)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == WALL)
				mlx_put_image_to_window(game->mlx,
					game->win, game->wall_img, width * TILE_SIZE, height * TILE_SIZE);
			if (game->map[height][width] == COLLECTABLE)
				mlx_put_image_to_window(game->mlx, game->win, game->collect_img, width * TILE_SIZE, height * TILE_SIZE);
			if (game->map[height][width] == PLAYER)
				place_player(game, height, width);
			if (game->map[height][width] == EXIT)
				mlx_put_image_to_window(game->mlx,
					game->win, game->exit_img, width * TILE_SIZE, height * TILE_SIZE);
			if (game->map[height][width] == EMPTY)
				mlx_put_image_to_window(game->mlx,
					game->win, game->empty_img, width * TILE_SIZE, height * TILE_SIZE);
			if (game->map[height][width] == ENEMY)
				mlx_put_image_to_window(game->mlx,
					game->win, game->enemy_img, width * TILE_SIZE, height * TILE_SIZE);
			width++;
		}
		height++;
	}
	draw_text(*game);
}

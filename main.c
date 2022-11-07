#include "so_long.h"

int	quit_game(t_game *game)
{
	int	line;

	line = 0;
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	while (line < game->win_height - 1)
		free(game->map[line++]);
	free(game->map);
    ft_printf("GOOD GAME\n\n");
	exit(0);
}

void    game_init(t_game *game)
{
    game->img_size = TILE_SIZE;
    game->moves_count = 0;
    game->exit_count = 0;
    game->player_count = 0;
    game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (game->win_width * TILE_SIZE + TILE_SIZE), (game->win_height * TILE_SIZE), "so_long");
	add_img(game);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (error_message("please select a map."));
    if (!ber_file(av[1]))
        return (error_message("please select a .ber file"));
	ft_memset(&game, 0, sizeof(t_game));
	map_reading(&game, av);
	check_errors(&game);
    game_init(&game);
	render(&game);
	mlx_key_hook(game.win, input, &game);
	mlx_hook(game.win, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlx);
}
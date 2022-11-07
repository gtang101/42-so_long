#include "../so_long.h"

static int	check_horizontal(t_game *game)
{
	int	i;
	int	j;

	i = game->win_width;
	j = 0;
	while (j < i)
	{
		if (game->map[0][i] != '1' && game->map[game->win_height - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

static int	check_vertical(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->win_width;
	while (height < game->win_height)
	{
		if (!(game->map[height][0] == '1' && game->map[height][width - 1] == '1'))
			return (0);
		height++;
	}
	return (1);
}

static void	check_walls(t_game *game)
{
	int	verticalwalls;
	int	horizontalwalls;

	verticalwalls = check_vertical(game);
	horizontalwalls = check_horizontal(game);
	if (!verticalwalls || !horizontalwalls)
	{
		ft_printf("\n\nThis map is missing the walls\n\n");
		quit_game(game);
	}
}

void	check_map_characters(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->win_height - 1)
	{
		width = 0;
		while (width <= game->win_width)
		{
			assign_count(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->player_count == 1 && game->collects_count > 1
			&& game->exit_count == 1))
	{
		ft_printf("\n\nMore than 1 player/exit or no collectable\n\n");
		quit_game(game);
	}
}

void	check_errors(t_game *game)
{
	check_walls(game);
	check_map_characters(game);
}

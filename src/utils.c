#include "../so_long.h"

int	ft_strend_cmp(char *name, char *end)
{
	int	name_len;
	int	ext_len;

	name_len = ft_strlen(name);
	ext_len = ft_strlen(end);
	if (name_len <= ext_len)
		return (0);
	name += name_len - ext_len;
	while (*name)
	{
		if (*name != *end)
			return (0);
		name++;
		end++;
	}
	return (1);
}

int	ber_file(char *file)
{
	if (!ft_strend_cmp(file, ".ber"))
		return (0);
	return (1);
}

int	error_message(char *message)
{
	ft_printf("ERROR, %s\n\n", message);
	return (0);
}

void	assign_count(t_game *game, int height, int width)
{
	if (game->map[height][width] != WALL &&
		game->map[height][width] != EMPTY &&
		game->map[height][width] != PLAYER &&
		game->map[height][width] != EXIT &&
		game->map[height][width] != COLLECTABLE &&
		game->map[height][width] != ENEMY &&
		game->map[height][width] != '\n')
	{
		ft_printf("INVALID MAP, UNIDENTIFIED CHAR\n\n");
		quit_game(game);
	}
	if (game->map[height][width] == COLLECTABLE)
			game->collects_count++;
	if (game->map[height][width] == PLAYER)
			game->player_count++;
	if (game->map[height][width] == EXIT)
			game->exit_count++;
}
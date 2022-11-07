#include "../so_long.h"

static int	right_move(t_game *game, int i, int j)
{
	if (game->map[j][i] == EXIT)
	{
		if (game->collects_count != 0)
			return (0);
		ft_printf("\n\nYOU WIN\n\n");
		quit_game(game);
	}
	if (game->map[j][i] == ENEMY)
	{
		ft_printf("\n\nYOU DIED\n\n");
		quit_game(game);
	}
	if (game->map[j][i] == EMPTY || game->map[j][i] == COLLECTABLE)
	{
		if (game->map[j][i] == COLLECTABLE)
			game->collects_count--;
		game->map[j][i] = 'P';
		game->player.p_pos_x = i;
		game->player.p_pos_y = j;
		game->moves_count++;
	}
	return (1);
}

static int	keyboard_w_s(t_game *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->player.p_pos_x;
	j = game->player.p_pos_y;
	if (movement == KEY_UP)
	{
		j--;
		if (game->map[j][i] == WALL)
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j + 1][i] = EMPTY;
	}
	else if (movement == KEY_DOWN)
	{
		j++;
		if (game->map[j][i] == WALL)
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j - 1][i] = EMPTY;
	}
	ft_printf("Steps Taken: %i\n", game->moves_count);
	ft_printf("Collectables Left: %i\n", game->collects_count);
	return (1);
}

static int	keyboard_a_d(t_game *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->player.p_pos_x;
	j = game->player.p_pos_y;
	if (movement == KEY_LEFT)
	{
		i--;
		if (game->map[j][i] == WALL)
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j][i + 1] = EMPTY;
	}
	else if (movement == KEY_RIGHT)
	{
		i++;
		if (game->map[j][i] == WALL)
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j][i - 1] = EMPTY;
	}
	ft_printf("Steps Taken: %i\n", game->moves_count);
	return (1);
}

int	input(int command, t_game *game)
{
	int	valid;

	if (command == ESC)
		quit_game(game);
	if (command == KEY_UP)
		valid = keyboard_w_s(game, command);
	if (command == KEY_DOWN)
		valid = keyboard_w_s(game, command);
	if (command == KEY_LEFT)
		valid = keyboard_a_d(game, command);
	if (command == KEY_RIGHT)
		valid = keyboard_a_d(game, command);
	if (valid)
		render(game);
	return (1);
}

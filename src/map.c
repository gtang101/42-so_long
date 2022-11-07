#include "../so_long.h"

static int	get_map_width(char *string)
{
	int	width;

	width = 0;
	while (string[width] != '\0')
		width++;
	if (string[width - 1] == '\n')
		width--;
	return (width);
}

static int	add_line(t_game *game, char *line)
{
	char	**temporary;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->win_height++;
	temporary = (char **)malloc(sizeof(char *) * (game->win_height + 1));
	temporary[game->win_height] = NULL;
	while (i < game->win_height - 1)
	{
		temporary[i] = game->map[i];
		i++;
	}
	temporary[i] = line;
	if (game->map)
		free(game->map);
	game->map = temporary;
	return (1);
}

int	map_reading(t_game *game, char **av)
{
	char	*readmap;
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (0);
	while (1)
	{
		readmap = get_next_line(fd);
		if (!add_line(game, readmap))
			break ;
	}
	close (fd);
	game->win_width = get_map_width(game->map[0]);
	return (1);
}

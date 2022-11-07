#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"

# define TILE_SIZE 32

// All possible tile types and tile structs
typedef enum e_tiletype
{
	EMPTY = '0', 
	WALL = '1', 
	COLLECTABLE = 'C', 
	PLAYER = 'P',
	EXIT = 'E',
	ENEMY = 'M'
}	t_tiletype;

// All possible key action
enum e_keycode
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	ESC = 53,
	CLOSE_WINDOW = 17
};

// Player

typedef struct s_player
{
	int		p_pos_x;
	int		p_pos_y;
	void	*player_img;
}			t_player;


// GAME
typedef struct	s_game
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;

	char		**map;

	int			moves_count;
	int			collects_count;
	int			player_count;
	int			exit_count;

	t_player	player;

	int			img_size;
	void		*wall_img;
	void		*empty_img;
	void		*exit_img;
	void		*enemy_img;
	void		*collect_img;
}				t_game;

int		quit_game(t_game *game);
int		map_reading(t_game *game, char **argv);
int		input(int command, t_game *game);
void	render(t_game *game);
void	add_img(t_game *game);
void	check_errors(t_game *game);
int		ber_file(char *file);
int		error_message(char *message);
void	assign_count(t_game *game, int height, int width);

#endif

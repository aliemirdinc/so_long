/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:34:03 by aldinc            #+#    #+#             */
/*   Updated: 2024/12/18 15:23:41 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include	"../lib/minilibx-linux/mlx.h"
# include	"../lib/libft/libft.h"
# include	<fcntl.h>

# define IMG_HEIGHT			32
# define IMG_WIDTH			32

# define ANIM_SPEED			1000

# define WIN_H				1080
# define WIN_W				1920

# define WALL				'1'
# define FLOOR 				'0'
# define COINS  			'C'
# define PLAYER				'P'
# define MAP_EXIT 		 	'E'

# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100

# define KEY_UP  			65362
# define KEY_LEFT  			65361
# define KEY_RIGHT 			65363
# define KEY_DOWN  			65364

# define KEY_Q				113
# define KEY_ESC			65307

# define WALL_XPM			"assets/textures/wall/wall.xpm"
# define FLOOR_XPM			"assets/textures/floor.xpm"
# define COINS_XPM			"assets/textures/collactable/000.xpm"
# define PLAYER_FRONT_XPM	"assets/textures/player/front/player17.xpm"
# define PLAYER_LEFT_XPM	"assets/textures/player/left/player9.xpm"
# define PLAYER_RIGHT_XPM	"assets/textures/player/right/player1.xpm"
# define PLAYER_BACK_XPM	"assets/textures/player/back/player25.xpm"
# define OPEN_EXIT_XPM		"assets/textures/opened_door.xpm"
# define EXIT_CLOSED_XPM	"assets/textures/dungeon_door.xpm"

# define GREEN				"\033[0;32m"
# define RED 				"\033[1;31m"
# define GREY 				"\033[0;90m"
# define CYAN				"\033[1;96m"
# define RESET 				"\033[0m"

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_position
{
	int	x;
	int	y;
}	t_positon;

typedef enum e_direction
{
	FRONT,
	BACK,
	LEFT,
	RIGHT
}	t_direction;

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_map
{
	char		**full;
	int			rows;
	int			columns;
	int			coins;
	int			exit;
	int			players;
	t_positon	player;
}	t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			movements;
	t_direction	player_direction;
	t_map		map;
	t_bool		map_alloc;
	t_image		undefined_image;
	t_image		wall;
	t_image		floor;
	t_image		coins;
	t_image		open_exit;
	t_image		exit_closed;
	t_image		player_front;
	t_image		player_left;
	t_image		player_right;
	t_image		player_back;
}	t_game;

void	ft_check_map(t_game *game);
void	ft_check_command_line_args(int argc, char const *argv[], t_game *game);
void	ft_check_for_empty_line(char *map, t_game *game);
void	ft_error_msg(char *msg, t_game *game);
void	ft_init_game(t_game *game);
void	ft_init_map(t_game *game, char *argv);
void	ft_free_all_allocated_memory(t_game *game);
void	ft_free_map(t_game *game);
void	ft_free_just_map(t_map *map);
void	check_as_a_hero(t_game *game);
int		key_hook(int keycode, t_game *game);
int		ft_check_all_collectables(t_map *map_c, t_map *map_e, t_game *game);
void	ft_handle_buttons(t_game *game);
int		ft_destroy_window(t_game *game);
void	ft_congrats_message(void);
int		ft_render_frame(t_game *game);
int		ft_update_frame(t_game *game);
void	ft_print_map_full(t_game *game);

#endif
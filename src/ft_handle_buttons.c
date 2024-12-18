/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_buttons.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:33:18 by aldinc            #+#    #+#             */
/*   Updated: 2024/12/17 17:37:03 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_object(t_game *game, int x, int y)
{
	if (game->map.full[y][x] == COINS)
		game->map.coins--;
	else if (game->map.full[y][x] == MAP_EXIT && game->map.coins == 0)
	{
		ft_congrats_message();
		ft_destroy_window(game);
	}
}

void	ft_move_direction(t_game *game, int dx, int dy)
{
	int	x;
	int	y;

	x = game->map.player.x;
	y = game->map.player.y;
	if (game->map.full[y + dy][x + dx] != WALL &&
	(game->map.full[y + dy][x + dx] != MAP_EXIT || game->map.coins == 0))
	{
		ft_check_object(game, x + dx, y + dy);
		game->map.full[y][x] = FLOOR;
		game->map.player.x += dx;
		game->map.player.y += dy;
		game->map.full[y + dy][x + dx] = PLAYER;
		game->movements++;
	}
}

void	ft_player_move(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		game->player_direction = BACK;
		ft_move_direction(game, 0, -1);
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		game->player_direction = FRONT;
		ft_move_direction(game, 0, 1);
	}
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		game->player_direction = LEFT;
		ft_move_direction(game, -1, 0);
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		game->player_direction = RIGHT;
		ft_move_direction(game, 1, 0);
	}
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
		ft_destroy_window(game);
	ft_player_move(keycode, game);
	ft_print_map_full(game);
	ft_printf(CYAN"The player's new"
		" position: (%d, %d)\nAll of coins: %d, Movements: %d\n"
		RESET, game->map.player.x, game->map.player.y,
		game->map.coins, game->movements);
	return (0);
}

void	ft_handle_buttons(t_game *game)
{
	mlx_hook(game->win_ptr, 2, 1l << 0, key_hook, game);
	mlx_hook(game->win_ptr, 17, 0, ft_destroy_window, game);
	mlx_hook(game->win_ptr, 12, 0, ft_render_frame, game);
}

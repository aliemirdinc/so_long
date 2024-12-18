/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:33:56 by aldinc            #+#    #+#             */
/*   Updated: 2024/12/17 18:49:39 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_map_full(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		ft_printf("%s|size: %d\n", game->map.full[i],
			(int)ft_strlen(game->map.full[i]));
		i++;
	}
}

int	main(int argc, const char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		ft_error_msg("Memory allocation failed for game", game);
	ft_check_command_line_args(argc, argv, game);
	ft_init_map(game, (char *)argv[1]);
	ft_init_game(game);
	ft_check_map(game);
	ft_printf("player's x = %d, player's y = %d\n",
		game->map.player.x, game->map.player.y);
	mlx_loop_hook(game->mlx_ptr, ft_render_frame, game);
	ft_handle_buttons(game);
	ft_printf(CYAN"***here***\n"RESET);
	mlx_loop(game->mlx_ptr);
	return (0);
}

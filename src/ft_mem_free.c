/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:33:39 by aldinc            #+#    #+#             */
/*   Updated: 2024/12/17 16:57:11 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy_images(t_game *game)
{
	int		i;
	t_image	*images[10];

	images[0] = &game->wall;
	images[1] = &game->floor;
	images[2] = &game->coins;
	images[3] = &game->player_front;
	images[4] = &game->player_left;
	images[5] = &game->player_right;
	images[6] = &game->player_back;
	images[7] = &game->exit_closed;
	images[8] = &game->open_exit;
	images[9] = NULL;
	i = 0;
	while (images[i])
	{
		if (images[i]->xpm_ptr)
			mlx_destroy_image(game->mlx_ptr, images[i]->xpm_ptr);
		free(images[i]);
		i++;
	}
}

void	ft_free_map(t_game *game)
{
	int	i;

	if (!game->map.full)
		return ;
	i = 0;
	while (i < game->map.rows)
		free(game->map.full[i++]);
	free(game->map.full);
}

void	ft_free_just_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		free(map->full[i]);
		i++;
	}
	free(map->full);
	free(map);
}

void	ft_free_all_allocated_memory(t_game *game)
{
	if (!game)
		return ;
	ft_destroy_images(game);
	ft_free_map(game);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	free(game);
}

int	ft_destroy_window(t_game *game)
{	
	if (!game)
	{
		ft_free_all_allocated_memory(game);
	}
	exit(0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:33:44 by aldinc            #+#    #+#             */
/*   Updated: 2024/12/16 18:36:38 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_msg(char *message, t_game *game)
{
	if (game)
	{
		if (game->map_alloc)
		{
			ft_free_map(game);
		}
		if (game->wall.xpm_ptr)
		{
			free(game->wall.xpm_ptr);
		}
		free(game);
		game = (NULL);
	}
	ft_printf(RED"ERROR: \n%s\n"RESET, message);
	exit(EXIT_FAILURE);
}

void	ft_congrats_message(void)
{
	ft_printf("\n");
	ft_printf(GREEN"===================================================\n"RESET);
	ft_printf(GREEN"                   🎉 CONGRATULATIONS! 🎉          \n"RESET);
	ft_printf(GREEN"---------------------------------------------------\n"RESET);
	ft_printf(GREEN" You have accomplished a great victory 🏆          \n"RESET);
	ft_printf(GREEN" Thanks for playing and being an awesome hero. 👑  \n"RESET);
	ft_printf(GREEN" its not the destination but the journey 💎        \n"RESET);
	ft_printf(GREEN"===================================================\n"RESET);
	ft_printf("\n");
}

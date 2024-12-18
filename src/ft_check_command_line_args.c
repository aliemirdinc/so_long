/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_command_line_args.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:45:25 by aldinc            #+#    #+#             */
/*   Updated: 2024/12/17 15:48:20 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_command_line_args(int argc, char const **argv, t_game *game)
{
	int	map_len;

	if (argc < 2)
		ft_error_msg("Where is the map bro? Please Enter a map!", game);
	if (argc > 2)
		ft_error_msg("You entered alot of argument. "
			"You must enter one map file without game", game);
	map_len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][map_len - 4], ".ber", 4))
		ft_error_msg("Map file is not valid. "
			"You can enter just .ber file.", game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaoloni <fpaoloni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:53:04 by fpaoloni          #+#    #+#             */
/*   Updated: 2023/05/24 16:54:42 by fpaoloni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	ft_validate_path(t_game *game)
{
	ft_floodfill(game, game->x, game->y);
	if (game->c_count != 0)
		ft_error_message(E_PATH_C, game);
	ft_restore(game);
	if (game->exit_possible == 0)
		ft_error_message(E_PATH_E, game);
}

void	ft_floodfill(t_game *game, int x, int y)
{
	if (x <= 0 || x >= game->columns || y <= 0 || y >= game->rows
		|| game->map[y][x] == '1' || game->map[y][x] == 'c'
		|| game->map[y][x] == 'o' || game->map[y][x] == 'e'
		|| game->map[y][x] == 'E')
	{
		if (game->map[y][x] == 'E')
			game->exit_possible = 1;
		return ;
	}
	if (game->map[y][x] == 'C')
	{
		game->c_count--;
		game->map[y][x] = 'c';
	}
	else if (game->map[y][x] == '0')
		game->map[y][x] = 'o';
	ft_floodfill(game, x, (y + 1));
	ft_floodfill(game, x, (y - 1));
	ft_floodfill(game, (x + 1), y);
	ft_floodfill(game, (x - 1), y);
}

void	ft_restore(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			if (game->map[y][x] == 'c')
			{
				game->map[y][x] = 'C';
				game->c_count++;
			}
			else if (game->map[y][x] == 'e')
				game->map[y][x] = 'E';
			else if (game->map[y][x] == 'o')
				game->map[y][x] = '0';
			x++;
		}
		y++;
	}
}

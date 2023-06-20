/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaoloni <fpaoloni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:07:02 by fpaoloni          #+#    #+#             */
/*   Updated: 2023/05/24 16:09:38 by fpaoloni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	check_map(t_game *game)
{
	ft_validate_chars(game);
	ft_validate_amount_chars(game);
	ft_validate_rectangle(game);
	ft_validate_wall(game);
	ft_validate_path(game);
}

void	ft_validate_chars(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] != '0' && game->map[y][x] != '1'
				&& game->map[y][x] != 'E' && game->map[y][x] != 'P'
				&& game->map[y][x] != 'C' && game->map[y][x] != 'X')
				ft_error_message(E_CHARACTER, game);
			x++;
		}
		y++;
	}
}

void	ft_validate_amount_chars(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				game->c_count++;
			if (game->map[y][x] == 'E')
				game->e_count++;
			if (game->map[y][x] == 'P')
			{
				game->p_count++;
				game->x = x;
				game->y = y;
			}
			x++;
		}
		y++;
	}
	if (game->p_count != 1 || game->e_count != 1 || game->c_count < 1)
		ft_error_message(E_CHARS, game);
}

void	ft_validate_rectangle(t_game *game)
{
	int	i;
	int	y;

	i = ft_strlen(game->map[0]);
	y = 1;
	while (game->map[y])
	{
		if (i != (int)ft_strlen(game->map[y]))
			ft_error_message(E_INVALIDMAP, game);
		y++;
	}
	game->rows = y;
	game->columns = i;
}

void	ft_validate_wall(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if ((y == 0 || y == (game->rows - 1)) && game->map[y][x] != '1')
				(ft_error_message(E_WALLS_TOP_BOTTOM, game));
			if ((x == 0 || x == (game->columns - 1)) && game->map[y][x] != '1')
				ft_error_message(E_WALLS_SIDES, game);
			x++;
		}
		y++;
	}
}

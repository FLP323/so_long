/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaoloni <fpaoloni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:16:57 by fpaoloni          #+#    #+#             */
/*   Updated: 2023/05/22 17:38:18 by fpaoloni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_keyboard(int keyhook, t_game *game)
{
	if (keyhook == K_ESC)
		ft_close_window(game);
	if (game->c_count == 0 && ((keyhook == K_RIGHT && game->map[game->y][game->x
				+ 1] == 'E') || (keyhook == K_DOWN && game->map[game->y
				+ 1][game->x] == 'E') || (keyhook == K_LEFT
				&& game->map[game->y][game->x - 1] == 'E') || (keyhook == K_UP
				&& game->map[game->y - 1][game->x] == 'E')))
	{
		ft_printf("You Win!\n");
		ft_close_window(game);
	}
	if (keyhook == K_UP && game->map[game->y - 1][game->x] != '1'
		&& game->map[game->y - 1][game->x] != 'E')
		ft_move_up(game);
	if (keyhook == K_LEFT && game->map[game->y][game->x - 1] != '1'
		&& game->map[game->y][game->x - 1] != 'E')
		ft_move_left(game);
	if (keyhook == K_DOWN && game->map[game->y + 1][game->x] != '1'
		&& game->map[game->y + 1][game->x] != 'E')
		ft_move_down(game);
	if (keyhook == K_RIGHT && game->map[game->y][game->x + 1] != '1'
		&& game->map[game->y][game->x + 1] != 'E')
		ft_move_right(game);
	return (0);
}

void	ft_move_up(t_game *game)
{
	game->map[game->y][game->x] = '0';
	if (game->map[game->y - 1][game->x] == 'C')
		game->c_count--;
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"./assets/player_up.xpm", &game->pxl, &game->pxl);
	game->map[game->y - 1][game->x] = 'P';
	game->y--;
	game->mov++;
	ft_printf("Mov: %d\n", game->mov);
}

void	ft_move_down(t_game *game)
{
	game->map[game->y][game->x] = '0';
	if (game->map[game->y + 1][game->x] == 'C')
		game->c_count--;
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"./assets/player_down.xpm", &game->pxl, &game->pxl);
	game->map[game->y + 1][game->x] = 'P';
	game->y++;
	game->mov++;
	ft_printf("Mov: %d\n", game->mov);
}

void	ft_move_left(t_game *game)
{
	game->map[game->y][game->x] = '0';
	if (game->map[game->y][game->x - 1] == 'C')
		game->c_count--;
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"./assets/player_left.xpm", &game->pxl, &game->pxl);
	game->map[game->y][game->x - 1] = 'P';
	game->x--;
	game->mov++;
	ft_printf("Mov: %d\n", game->mov);
}

void	ft_move_right(t_game *game)
{
	game->map[game->y][game->x] = '0';
	if (game->map[game->y][game->x + 1] == 'C')
		game->c_count--;
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"./assets/player_right.xpm", &game->pxl, &game->pxl);
	game->map[game->y][game->x + 1] = 'P';
	game->x++;
	game->mov++;
	ft_printf("Mov: %d\n", game->mov);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_two_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaoloni <fpaoloni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:23:51 by fpaoloni          #+#    #+#             */
/*   Updated: 2023/05/24 18:19:56 by fpaoloni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	ft_put_enemy(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->enemy, game->pxl
		* x, game->pxl * y);
}

void	ft_put_blank(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->blank, game->pxl
		* x, game->pxl * y);
}

void	enemy_left(t_game *game)
{
	if (game->enemy)
		mlx_destroy_image(game->mlx, game->enemy);
		game->enemy = mlx_xpm_file_to_image(game->mlx,
			"./assets/enemy_left.xpm", &game->pxl, &game->pxl);
}

void	enemy_right(t_game *game)
{
	if (game->enemy)
		mlx_destroy_image(game->mlx, game->enemy);
		game->enemy = mlx_xpm_file_to_image(game->mlx,
			"./assets/enemy_right.xpm", &game->pxl, &game->pxl);
}

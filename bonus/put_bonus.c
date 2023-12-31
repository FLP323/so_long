/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaoloni <fpaoloni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:20:26 by fpaoloni          #+#    #+#             */
/*   Updated: 2023/05/24 16:21:32 by fpaoloni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	ft_put_limits(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->limits,
		game->pxl * x, game->pxl * y);
}

void	ft_put_floor(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor,
		game->pxl * x, game->pxl * y);
}

void	ft_put_collect(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->collect,
		game->pxl * x, game->pxl * y);
}

void	ft_put_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->player, game->pxl
		* game->x, game->pxl * game->y);
}

void	ft_put_exit(t_game *game, int x, int y)
{
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->c_count == 0)
		game->exit = mlx_xpm_file_to_image(game->mlx,
				"./assets/open.xpm", &game->pxl, &game->pxl);
	else
		game->exit = mlx_xpm_file_to_image(game->mlx,
				"./assets/close.xpm", &game->pxl, &game->pxl);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit, game->pxl * x,
		game->pxl * y);
}

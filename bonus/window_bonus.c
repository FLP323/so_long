/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaoloni <fpaoloni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:12:57 by fpaoloni          #+#    #+#             */
/*   Updated: 2023/05/24 19:33:45 by fpaoloni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	ft_window(t_game *game)
{
	game->pxl = 64;
	game->mlx = mlx_init();
	if (!game->mlx)
		exit(EXIT_FAILURE);
	game->mlx_win = mlx_new_window(game->mlx, game->pxl * game->columns,
			game->pxl * (game->rows + 1), "42 SoLong by fpaoloni");
	init_assets(game);
	mlx_loop_hook(game->mlx, &ft_draw_map, game);
	mlx_hook(game->mlx_win, 2, 1L << 0, ft_keyboard, game);
	mlx_hook(game->mlx_win, 17, 1L << 5, ft_close_window, game);
	mlx_loop(game->mlx);
}

int	ft_draw_map(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->rows)
	{
		x = -1;
		while (++x < game->columns)
			ft_put_select(game, x, y);
	}
	y = game->rows - 1;
	while (++y < game->rows + 1)
	{
		x = -1;
		while (++x < game->columns)
			ft_mov_to_str(game, x, y);
	}
	return (1);
}

int	ft_close_window(t_game *game)
{
	ft_free_map_2d(game->map);
	close_img(game);
	mlx_destroy_window(game->mlx, game->mlx_win);
	free(game);
	exit(1);
	return (0);
}

void	ft_put_select(t_game *game, int x, int y)
{
	if (game->map[y][x] == '0')
		ft_put_floor(game, x, y);
	if (game->map[y][x] == '1')
		ft_put_limits(game, x, y);
	if (game->map[y][x] == 'C')
		ft_put_collect(game, x, y);
	if (game->map[y][x] == 'P')
		ft_put_player(game);
	if (game->map[y][x] == 'E')
		ft_put_exit(game, x, y);
	if (game->map[y][x] == 'X')
	{
		ft_animated(game, x, y);
		ft_put_enemy(game, x, y);
	}
}

void	ft_mov_to_str(t_game *game, int x, int y)
{
	char	*str;

	str = ft_itoa(game->mov);
	ft_put_blank(game, x, y);
	mlx_string_put(game->mlx, game->mlx_win, (game->columns / 2) * game->pxl,
		(game->rows + 1) * game->pxl * 0.94, 0xFFFFFF, str);
	free(str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaoloni <fpaoloni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:53:09 by fpaoloni          #+#    #+#             */
/*   Updated: 2023/05/24 17:44:31 by fpaoloni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	init_data(t_game *game)
{
	game->map = NULL;
	game->c_count = 0;
	game->e_count = 0;
	game->p_count = 0;
	game->mov = 0;
	game->x = 0;
	game->y = 0;
	game->rows = 0;
	game->columns = 0;
	game->exit_possible = 0;
	game->exit = 0;
	game->loop = 0;
	game->direction = 1;
}

void	ft_animated(t_game *game, int x, int y)
{
	if ((game->map[y][x - 1] == '1' && game->map[y][x + 1] == '1'))
		return ;
	game->loop++;
	if (game->map[y][x - 1] != '0' && game->map[y][x - 1] != 'P')
	{
		game->direction = 1;
		enemy_right(game);
	}
	else if (game->map[y][x + 1] != '0' && game->map[y][x + 1] != 'P')
	{
		game->direction = -1;
		enemy_left(game);
	}
	if (game->loop % 10 == 0)
	{
		if (game->map[y][x + game->direction] == 'P')
			ft_close_window(game);
		game->map[y][x] = '0';
		game->map[y][x + game->direction] = 'X';
	}
	if (game->loop == 1000)
		game->loop = 0;
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (0);
	init_data(game);
	if (argc != 2)
		ft_error_message(E_ARG, game);
	read_map(argv[1], game);
	check_map(game);
	ft_window(game);
	return (0);
}

void	close_img(t_game *game)
{
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->limits)
		mlx_destroy_image(game->mlx, game->limits);
	if (game->collect)
		mlx_destroy_image(game->mlx, game->collect);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->enemy)
		mlx_destroy_image(game->mlx, game->enemy);
	if (game->blank)
		mlx_destroy_image(game->mlx, game->blank);
}

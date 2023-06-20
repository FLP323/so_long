/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaoloni <fpaoloni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:58:39 by fpaoloni          #+#    #+#             */
/*   Updated: 2023/05/24 19:25:11 by fpaoloni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	ft_error_message(char *str, t_game *game)
{
	if (!str)
		ft_printf("Error: ./so_long");
	else
		ft_printf("ERROR\n%s\n", str);
	if (game->map)
		ft_free_map_2d(game->map);
	free(game);
	exit(1);
}

void	ft_free_map_2d(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void	read_map(char *map_path, t_game *game)
{
	char	*str_map;
	int		fd;
	char	c;
	int		count;

	count = 0;
	ft_validate_file(map_path, game);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		ft_error_message(E_FILE, game);
	while (read(fd, &c, 1) == 1)
		count++;
	if (count == 0)
		ft_error_message(E_EMPTYFILE, game);
	str_map = (char *)malloc(sizeof(char) * (count + 1));
	if (!str_map)
		ft_error_message(E_MALLOC, game);
	close(fd);
	fd = open(map_path, O_RDONLY);
	read(fd, str_map, count);
	str_map[count] = '\0';
	close(fd);
	game->map = ft_split(str_map, '\n');
	free(str_map);
}

void	ft_validate_file(char *map_path, t_game *game)
{
	int	i;

	i = ft_strlen(map_path) - 1;
	if (map_path[i] != 'r')
		ft_error_message(E_FORMAT, game);
	i--;
	if (map_path[i] != 'e')
		ft_error_message(E_FORMAT, game);
	i--;
	if (map_path[i] != 'b')
		ft_error_message(E_FORMAT, game);
	i--;
	if (map_path[i] != '.')
		ft_error_message(E_FORMAT, game);
}

void	init_assets(t_game *game)
{
	game->floor = mlx_xpm_file_to_image(game->mlx,
			"./assets/floor.xpm", &game->pxl, &game->pxl);
	game->limits = mlx_xpm_file_to_image(game->mlx,
			"./assets/wall.xpm", &game->pxl, &game->pxl);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"./assets/player_down.xpm", &game->pxl, &game->pxl);
	game->collect = mlx_xpm_file_to_image(game->mlx,
			"./assets/collect.xpm", &game->pxl, &game->pxl);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"./assets/close.xpm", &game->pxl, &game->pxl);
	game->enemy = mlx_xpm_file_to_image(game->mlx,
			"./assets/enemy_right.xpm", &game->pxl, &game->pxl);
	game->blank = mlx_xpm_file_to_image(game->mlx,
			"./assets/blank.xpm", &game->pxl, &game->pxl);
}

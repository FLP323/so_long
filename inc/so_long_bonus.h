/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_Long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaoloni <fpaoloni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:51:43 by fpaoloni          #+#    #+#             */
/*   Updated: 2023/05/24 17:43:10 by fpaoloni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"
# include <fcntl.h>

# define K_ESC 53
# define K_UP 13
# define K_DOWN 1
# define K_LEFT 0
# define K_RIGHT 2

# define E_MALLOC "Failed to allocate memory!"
# define E_ARG "You forgot to select a map!"
# define E_FILE "The file could not be opened!"
# define E_CHARACTER "An invalid character was found!"
# define E_CHARS "The map does not contain the required characters!"
# define E_INVALIDMAP "The map must be rectangular!"
# define E_WALLS_TOP_BOTTOM "The map is missing a wall on the top or bottom"
# define E_WALLS_SIDES "The map is missing a wall on the left or right side"
# define E_PATH_C "The player can't reach all the collectibles"
# define E_PATH_E "The player can't reach the exit"
# define E_FORMAT "The file type must be .ber!"
# define E_EMPTYFILE "The file is empty!"
# define E_IMAGE "There is something wrong with the image you want to put."

typedef struct s_game
{
	char	**map;
	int		c_count;
	int		e_count;
	int		p_count;
	int		rows;
	int		columns;
	int		exit_possible;
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
	int		mov;
	int		pxl;
	void	*limits;
	void	*floor;
	void	*collect;
	void	*player;
	void	*exit;
	void	*enemy;
	void	*blank;
	int		loop;
	int		direction;
}			t_game;

void		check_map(t_game *game);
void		ft_validate_chars(t_game *game);
void		ft_validate_amount_chars(t_game *game);
void		ft_validate_wall(t_game *game);
void		ft_validate_rectangle(t_game *game);

void		ft_put_limits(t_game *game, int x, int y);
void		ft_put_floor(t_game *game, int x, int y);
void		ft_put_collect(t_game *game, int x, int y);
void		ft_put_player(t_game *game);
void		ft_put_exit(t_game *game, int x, int y);
void		ft_put_enemy(t_game *game, int x, int y);
void		ft_put_blank(t_game *game, int x, int y);

void		ft_move_up(t_game *game);
void		ft_move_down(t_game *game);
void		ft_move_left(t_game *game);
void		ft_move_right(t_game *game);
int			ft_keyboard(int keyhook, t_game *game);

void		ft_floodfill(t_game *game, int x, int y);
void		ft_restore(t_game *game);
void		ft_validate_path(t_game *game);

void		close_img(t_game *game);
void		init_data(t_game *game);

void		ft_validate_file(char *map_path, t_game *game);
void		read_map(char *map_path, t_game *game);
void		ft_error_message(char *str, t_game *game);
void		ft_free_map_2d(char **map);

void		ft_window(t_game *game);
int			ft_close_window(t_game *game);
int			ft_draw_map(t_game *game);
void		init_assets(t_game *game);
void		ft_mov_to_str(t_game *game, int x, int y);
void		ft_put_select(t_game *game, int x, int y);
void		ft_animated(t_game *game, int x, int y);
void		enemy_left(t_game *game);
void		enemy_right(t_game *game);
#endif

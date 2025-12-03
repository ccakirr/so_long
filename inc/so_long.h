/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:17:12 by ccakir            #+#    #+#             */
/*   Updated: 2025/12/03 20:15:03 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TILE 64

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../my_libs/minilibx-linux/mlx.h"
# include "../my_libs/get_next_line/get_next_line.h"
# include "../my_libs/ft_printf/ft_printf.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		w;
	int		h;
	int		px;
	int		py;
	int		c_left;
	int		frame;
	int		game_over_timer;
	int		game_over;
	int		coin_frame;
	int		movement_count;
	void	*img_floor;
	void	*img_wall;
	void	*img_door_closed;
	void	*img_door_opened;
	void	*img_player_idle;
	void	*img_game_over;
	void	*coin[4];
}			t_game;

char	*ft_strtrim(char const	*str, char const	*set);
int		check_map(char *map_file);
char	**read_map_file(char	*map_file);
void	validate_map(t_game *game);
int		map_len(char	**map);
char	**map_dup(char	**map);
void	error_exit(char	*msg);
void	free_map(char	**map);
void	find_player(t_game	*game);
void	flood_fill(char	**map, t_game *game,
int 	*exit_reachable, int *collected_c);
int		count_collectables(t_game	*game);
void	validate_reachability(t_game *game);
void	load_static_textures(t_game *game);
void	load_coin_textures(t_game *game);
void	load_exit_textures(t_game *game);
void	load_player_walk_textures(t_game *game);
void	draw_tile(t_game *game, int x, int y, char c);
void	draw_map(t_game *game);
void	render_frame(t_game *game);
int		handle_input(int keycode, t_game *game);
void	game_init(t_game *game, char *map_path);
int		*make_all_array_zero(int *array, int len);
void	set_height_and_width(t_game	*game);
void	exit_game(t_game *game);
int		close_hook(t_game *game);
void	destroy_game_win(t_game	*game);

#endif
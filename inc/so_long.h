/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:17:12 by ccakir            #+#    #+#             */
/*   Updated: 2025/11/12 23:23:29 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TILE 64

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct s_game
{
	// --- MLX ---
	void	*mlx;
	void	*win;

	// --- Harita bilgileri ---
	char	**map;
	int		w;			// harita genişliği (tile sayısı)
	int		h;			// harita yüksekliği (tile sayısı)
	int		px;			// player x konumu
	int		py;			// player y konumu
	int		c_left;		// kalan coin sayısı

	// --- Genel durum ---
	int		frame;
	int		game_over_timer;  // Kaç frame geçti
	int		game_over;	// 1 → oyun bitti
	int		coin_frame;	// coin animasyon index
	int		movement_count;

	// --- Sabit sprite’lar ---
	void	*img_floor;			// floor.xpm
	void	*img_wall;			// wall.xpm
	void	*img_door_closed;	// door00.xpm
	void	*img_door_opened;	// door01.xpm
	void	*img_player_idle;	// playerdefault.xpm
	void	*img_game_over;		// istersen ekranda kullanılır

	// --- Animasyon dizileri ---
	void	*coin[4];			// coin00–03.xpm

}	t_game;



char	*ft_strtrim(char const	*str, char const	*set);
int		check_map(char *map_file);
char	**read_map_file(char	*map_file);
void	validate_map(t_game *game);
int		map_len(char	**map);
char	**map_dup(char	**map);
void	error_exit();
void	free_map(char	**map);
void	find_player(t_game	*game);
void	flood_fill(char	**map, int	y, int	x, int *exit_reachable, int *collected_C);
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
int		*make_all_array_zero(int	*array, int	len);
void	set_height_and_width(t_game	*game);
void	exit_game(t_game *game);
int		close_hook(t_game *game);
void	destroy_game_win(t_game	*game);




#endif
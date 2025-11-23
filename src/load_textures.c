/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:25:02 by ccakir            #+#    #+#             */
/*   Updated: 2025/11/23 16:04:04 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_static_textures(t_game *game)
{
	int	w;
	int	h;

	game->img_floor = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm", &w, &h);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &w, &h);
	game->img_door_closed = mlx_xpm_file_to_image(game->mlx, "assets/door00.xpm", &w, &h);
	game->img_door_opened = mlx_xpm_file_to_image(game->mlx, "assets/door01.xpm", &w, &h);
	game->img_player_idle = mlx_xpm_file_to_image(game->mlx, "assets/player/player.xpm", &w, &h);
	game->img_game_over = mlx_xpm_file_to_image(game->mlx, "assets/game_over.xpm", &w, &h);
	if (!game->img_floor || !game->img_wall || !game->img_door_closed
		|| !game->img_door_opened || !game->img_player_idle || !game->img_game_over)
		error_exit("Game textures can't loading!");
}

void	load_coin_textures(t_game *game)
{
	char	*coin_paths[5];
	int		i;
	int		h;
	int		w;

	coin_paths[0] = "assets/coins/coin00.xpm";
	coin_paths[1] = "assets/coins/coin01.xpm";
	coin_paths[2] = "assets/coins/coin02.xpm";
	coin_paths[3] = "assets/coins/coin03.xpm";
	coin_paths[4] = NULL;
	i = 0;
	while (coin_paths[i])
	{
		game->coin[i] = mlx_xpm_file_to_image(game->mlx, coin_paths[i], &w, &h);
		if (!(game->coin[i]))
			{
				write(1,"coin",ft_strlen("coin"));
				error_exit("Game textures can't loading!");
			}
		i++;
	}
}


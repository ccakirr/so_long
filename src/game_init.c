/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:48:43 by ccakir            #+#    #+#             */
/*   Updated: 2025/11/29 00:20:20 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	expose_hook(t_game *game)
{
	draw_map(game);
	return (0);
}

int	update_frame(t_game *game)
{
	game->frame++;
	if (game->game_over)
	{
		game->game_over_timer++;
		if (game->game_over_timer > 999)
			exit_game(game);
		mlx_clear_window(game->mlx, game->win);
		mlx_put_image_to_window(
			game->mlx,
			game->win,
			game->img_game_over,
			((game->w * TILE) - 1920) / 2,
			((game->h * TILE) - 1080) / 2
			);
		return (0);
	}
	if (game->frame % 5 == 0)
		game->coin_frame = (game->coin_frame + 1) % 4;
	draw_map(game);
	return (0);
}

void	set_zero(t_game *game)
{
	game->frame = 0;
	game->game_over_timer = 0;
	game->game_over = 0;
	game->coin_frame = 0;
	game->movement_count = 0;
}

void	check_mlx(t_game *game)
{
	if (!game->mlx)
	{
		free_map(game->map);
		error_exit("MLX init failed");
	}
	if (!game->win)
	{
		free_map(game->map);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		error_exit("MLX window creation failed");
	}
}

void	game_init(t_game *game, char *map_path)
{
	game->map = read_map_file(map_path);
	validate_map(game);
	find_player(game);
	validate_reachability(game);
	set_height_and_width(game);
	game->c_left = count_collectables(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->w * TILE,
			game->h * TILE, "so_long");
	check_mlx(game);
	load_static_textures(game);
	load_coin_textures(game);
	set_zero(game);
	draw_map(game);
	mlx_expose_hook(game->win, expose_hook, game);
	mlx_key_hook(game->win, handle_input, game);
	mlx_hook(game->win, 17, 0, close_hook, game);
	mlx_loop_hook(game->mlx, update_frame, game);
	mlx_loop(game->mlx);
}

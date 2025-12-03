/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 22:36:00 by ccakir            #+#    #+#             */
/*   Updated: 2025/11/29 02:50:10 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	end_still_reachable(t_game	*game)
{
	game->map = NULL;
	game->img_floor = NULL;
	game->img_wall = NULL;
	game->img_door_closed = NULL;
	game->img_door_opened = NULL;
	game->img_player_idle = NULL;
	game->img_game_over = NULL;
	game->win = NULL;
	game->mlx = NULL;
}

static void	destroy_images(t_game *game)
{
	int	i;

	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_door_closed)
		mlx_destroy_image(game->mlx, game->img_door_closed);
	if (game->img_door_opened)
		mlx_destroy_image(game->mlx, game->img_door_opened);
	if (game->img_player_idle)
		mlx_destroy_image(game->mlx, game->img_player_idle);
	if (game->img_game_over)
		mlx_destroy_image(game->mlx, game->img_game_over);
	i = 0;
	while (i < 4)
	{
		if (game->coin[i])
			mlx_destroy_image(game->mlx, game->coin[i]);
		i++;
	}
}

void	exit_game(t_game *game)
{
	if (game->map)
		free_map(game->map);
	destroy_images(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	end_still_reachable(game);
	exit(0);
}

int	close_hook(t_game *game)
{
	exit_game(game);
	return (0);
}

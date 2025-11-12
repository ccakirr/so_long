/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 22:36:00 by ccakir            #+#    #+#             */
/*   Updated: 2025/11/12 23:22:26 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_game *game)
{
	if (game->map)
		free(game->map);
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
	if (game->win)
	mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
}

int	close_hook(t_game *game)
{
	exit_game(game);
	return (0);
}
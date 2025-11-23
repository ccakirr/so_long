/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:10:20 by ccakir            #+#    #+#             */
/*   Updated: 2025/11/23 16:04:14 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*get_tile_image(t_game *game, char c)
{
	void	*img;

	img = NULL;
	if (c == '1')
		img = game->img_wall;
	else if (c == 'C')
		img = game->coin[game->coin_frame];
	else if (c == 'E' && game->c_left > 0)
		img = game->img_door_closed;
	else if (c == 'E')
		img = game->img_door_opened;
	else if (c == 'P')
		img = game->img_player_idle;
	return (img);
}

void	draw_tile(t_game *game, int x, int y, char c)
{
	void	*img;

	if (c != '1')
		if (game->img_floor)
			mlx_put_image_to_window(game->mlx, game->win,
				game->img_floor, x * TILE, y * TILE);
	img = get_tile_image(game, c);
	if (img)
		mlx_put_image_to_window(game->mlx, game->win, img, x * TILE, y * TILE);
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;
	
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			draw_tile(game, x, y, game->map[y][x]);
			x++;
		}
		y++;
	}
}

void	render_frame(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	draw_map(game);
}

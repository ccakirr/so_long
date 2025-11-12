/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:44:39 by ccakir            #+#    #+#             */
/*   Updated: 2025/11/12 22:53:04 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	can_move(t_game	*game, int	new_y, int	new_x)
{
	if (new_x < 0 || new_y < 0 || new_x >= game->w || new_y >= game->h)
		return (0);
	if (game->map[new_y][new_x] == '1')
		return (0);
	if (game->map[new_y][new_x] == 'E' && game->c_left > 0)
		return (0);
	return (1);
}

static void	collect_coin(t_game *game, int	x, int	y)
{
	if (game->map[y][x] == 'C')
	{
		game->c_left--;
		game->map[y][x] = '0';
	}
}

static void	check_exit(t_game	*game, int	x, int	y)
{
	if (game->c_left == 0 && game->map[y][x] == 'E')
		game->game_over = 1;
}

static void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->px + dx;
	new_y = game->py + dy;
	if (!can_move(game, new_y, new_x))
		return ;
	check_exit(game, new_x, new_y);
	game->map[game->py][game->px] = '0';
	game->py = new_y;
	game->px = new_x;
	collect_coin(game, new_x, new_y);
	game->map[new_y][new_x] = 'P';
	game->movement_count++;
	ft_printf("Moves: %d\n", game->movement_count);
}

int	handle_input(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit_game(game);
	if (game->game_over)
		return (0);
	if (keycode == 65362)
		move_player(game, 0, -1);
	else if (keycode == 65364)
		move_player(game, 0, 1);
	else if (keycode == 65361)
		move_player(game, -1, 0);
	else if (keycode == 65363)
		move_player(game, 1, 0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 22:49:04 by ccakir            #+#    #+#             */
/*   Updated: 2025/12/04 09:34:38 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_game	*game)
{
	int		i;
	int		j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->px = j;
				game->py = i;
				return ;
			}
			j++;
		}
		i++;
	}
	free_map(game->map);
	error_exit("Can't find player!");
}

void	flood_fill(char	**map, t_game *game,
					int *exit_reachable, int *collected_c)
{
	if (game->py < 0 || game->px < 0 || !map[game->py]
		|| game->px >= (int)ft_strlen(map[game->py]))
		return ;
	if (map[game->py][game->px] == '1' || map[game->py][game->px] == 'V')
		return ;
	if (map[game->py][game->px] == 'C')
		(*collected_c)++;
	if (map[game->py][game->px] == 'E')
	{
		*exit_reachable = 1;
		return ;
	}
	map[game->py][game->px] = 'V';
	flood_fill(map, game, exit_reachable, collected_c);
	game->px++;
	flood_fill(map, game, exit_reachable, collected_c);
	game->px -= 2;
	flood_fill(map, game, exit_reachable, collected_c);
	game->px++;
	game->py++;
	flood_fill(map, game, exit_reachable, collected_c);
	game->py -= 2;
	flood_fill(map, game, exit_reachable, collected_c);
	game->py++;
}

int	count_collectables(t_game	*game)
{
	int	i;
	int	j;
	int	total_c;

	i = 0;
	total_c = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				total_c++;
			j++;
		}
		i++;
	}
	return (total_c);
}

void	validate_reachability(t_game *game)
{
	char	**map_cpy;
	int		collected_c;
	int		exit_reachable;
	int		total_c;

	find_player(game);
	collected_c = 0;
	exit_reachable = 0;
	map_cpy = map_dup(game->map);
	total_c = count_collectables(game);
	flood_fill(map_cpy, game, &exit_reachable, &collected_c);
	if (!((collected_c == total_c) && (exit_reachable)))
	{
		free_map(map_cpy);
		free_map(game->map);
		error_exit("Map isn't obeys the rules!");
	}
	free_map(map_cpy);
}

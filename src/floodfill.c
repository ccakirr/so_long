/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 22:49:04 by ccakir            #+#    #+#             */
/*   Updated: 2025/11/23 16:04:41 by ccakir           ###   ########.fr       */
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
	error_exit("Can't find player!");
}

void	flood_fill(char	**map, int	y, int	x, int *exit_reachable, int *collected_C)
{
	if (y < 0 || x < 0 || !map[y] || x >= (int)ft_strlen(map[y]))
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C')
		(*collected_C)++;
	if (map[y][x] == 'E')
	{
		*exit_reachable = 1;
		return ;
	}
	map[y][x] = 'V';
	flood_fill(map, y + 1, x, exit_reachable, collected_C);
	flood_fill(map, y - 1, x, exit_reachable, collected_C);
	flood_fill(map, y, x + 1, exit_reachable, collected_C);
	flood_fill(map, y, x - 1, exit_reachable, collected_C);
}

int	count_collectables(t_game	*game)
{
	int	i;
	int	j;
	int	total_C;

	i = 0;
	total_C = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if(game->map[i][j] == 'C')
				total_C++;
			j++;
		}
		i++;
	}
	return (total_C);
}

void	validate_reachability(t_game *game)
{
	char	**map_cpy;
	int		collected_C;
	int		exit_reachable;
	int		total_C;

	collected_C = 0;
	exit_reachable = 0;
	map_cpy = map_dup(game->map);
	total_C = count_collectables(game);
	flood_fill(map_cpy, game->py, game->px, &exit_reachable, &collected_C);
	if(!((collected_C == total_C) || (exit_reachable)))
	{
		free_map(map_cpy);
		error_exit("Map isn't obeys the rules!");
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:54:21 by ccakir            #+#    #+#             */
/*   Updated: 2025/11/23 16:04:18 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_rectangle(char	**map)
{
	int	i;
	int	first_line_len;
	int current_len;

	if(!map || !map[0])
		return (0);
	i = 0;
	first_line_len = ft_strlen(map[i]);
	while (map[i])
	{
		current_len = ft_strlen(map[i]);
		if (current_len != first_line_len)
			return (0);
		i++;
	}
	return (1);
}

static int	check_walls(char	**map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		if (i == 0 || i == (map_len(map) - 1))
		{
			while (map[i][j])
			{
				if (!(map[i][j++] == '1'))
					return (0);
			}
		}
		else
		{
			if (map[i][0] != '1')
				return (0);
			if(map[i][(ft_strlen(map[i]) - 1)] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}

static int check_validate(int	*validate)
{
	if (validate[4] != 1 || validate[3] < 1 || validate[2] < 1)
		return (0);
	return (1);
}

static int	check_content(char **map)
{
	int	validate[5];
	int	i;
	int	j;

	i = 0;
	make_all_array_zero(validate, 5);
	while (map[i])
	{
		j = -1;
		while(map[i][++j])
		{
			if (map[i][j] == '0')
				validate[0] = validate[0] + 1;
			else if (map[i][j] == '1')
				validate[1] = validate[1] + 1;
			else if (map[i][j] == 'C')
				validate[2] = validate[2] + 1;
			else if (map[i][j] == 'E')
				validate[3] = validate[3] + 1;
			else if (map[i][j] == 'P')
				validate[4] = validate[4] + 1;
			else
				return (0);
		}
		i++;
	}
	return (check_validate(validate));
}

void	validate_map(t_game *game)
{
	if (!check_rectangle(game->map))
	{
		free_map(game->map);
		error_exit("Map is not rectangular");
	}
	if (!check_walls(game->map))
	{
		free_map(game->map);
		error_exit("Invalid walls");
	}
	if (!check_content(game->map))
	{
		free_map(game->map);
		error_exit("Invalid map content");
	}
	find_player(game);
	validate_reachability(game);
}

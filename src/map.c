/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:47:30 by ccakir            #+#    #+#             */
/*   Updated: 2025/11/23 16:04:09 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(char *map_file)
{
	int	len;

	len = ft_strlen(map_file);
	if (len < 5)
		return (0);
	if (map_file[len - 4] == '.'
		&& map_file[len - 3] == 'b'
		&& map_file[len - 2] == 'e'
		&& map_file[len - 1] == 'r')
			return (1);
	return (0);
}

static char	**add_line_to_map(char	**map, char	*line, int	count)
{
	char	**new_map;
	int		i;
	
	new_map = malloc(sizeof(char *) * (count + 2));
	if(!new_map)
		return (NULL);
	i = 0;
	if (map)
	{
		while(map[i])
		{
			new_map[i] = map[i];
			i++;
		}
		free(map);
	}
	new_map[i] = line;
	new_map[i + 1] = NULL;
	return (new_map);
}

char	**read_map_file(char	*map_file)
{
	int		fd;
	char	**map;
	char	*line;
	int		count;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	count = 0;
	map = NULL;
	while ((line = get_next_line(fd)))
	{
		line = ft_strtrim(line, "\n");
		if (!line)
			return (close(fd), NULL);
		map = add_line_to_map(map, line, count);
		if (!map)
		{
			free(line);
			return (close(fd), NULL);
		}
		count++;
	}
	close(fd);
	return (map);
}

void	set_height_and_width(t_game	*game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
		y++;
	game->h = y;
	y = y - 1;
	x = 0;
	while(game->map[y][x])
		x++;
	game->w = x;
}

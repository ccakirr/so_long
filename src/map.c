/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:47:30 by ccakir            #+#    #+#             */
/*   Updated: 2025/12/03 20:09:42 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_directory(char *map_file)
{
	int	fd;

	fd = open(map_file, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (1);
	}
	return (0);
}

static char	**add_line_to_map(char **map, char *line, int count)
{
	char	**new_map;
	int		i;

	new_map = malloc(sizeof(char *) * (count + 2));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < count)
	{
		new_map[i] = map[i];
		i++;
	}
	new_map[i] = line;
	new_map[i + 1] = NULL;
	free(map);
	return (new_map);
}

char	**read_map_file(char *map_file)
{
	int		fd;
	char	*line;
	char	*trimmed;
	int		count;
	char	**map;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = NULL;
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		trimmed = ft_strtrim(line, "\n");
		free(line);
		if (!trimmed)
			return (free_map(map), close(fd), NULL);
		map = add_line_to_map(map, trimmed, count++);
		if (!map)
			return (free_map(map), close(fd), NULL);
	}
	return (close(fd), map);
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
	while (game->map[y][x])
		x++;
	game->w = x;
}

int	check_map(char *map_file)
{
	int	len;

	len = ft_strlen(map_file);
	if (len < 5)
		return (0);
	if (map_file[len - 4] == '.'
		&& map_file[len - 3] == 'b'
		&& map_file[len - 2] == 'e'
		&& map_file[len - 1] == 'r'
		&& (access(map_file, R_OK) == 0)
		&& !(is_directory(map_file)))
		return (1);
	return (0);
}

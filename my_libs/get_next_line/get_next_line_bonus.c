/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 23:57:09 by ccakir            #+#    #+#             */
/*   Updated: 2025/08/27 14:49:39 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*add_storage(int fd, char *storage)
{
	int		read_byte;
	char	*buffer;

	if (!storage)
		storage = ft_substr("", 0, 0);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_byte = 1;
	while (!ft_strchr(storage, '\n') && read_byte > 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte < 0)
		{
			free(buffer);
			free(storage);
			return (NULL);
		}
		buffer[read_byte] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	free (buffer);
	return (storage);
}

static char	*ext_line(char *storage)
{
	int		i;
	char	*line;

	i = 0;
	if (!storage || !*storage)
		return (NULL);
	while (storage[i] != '\n' && storage[i])
		i++;
	if (storage[i] == '\n')
		line = ft_substr(storage, 0, i + 1);
	else
		line = ft_substr(storage, 0, i);
	return (line);
}

static char	*update_storage(char *storage)
{
	char	*new_storage;
	int		i;

	i = 0;
	while (storage[i] != '\n' && storage[i])
		i++;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	new_storage = ft_substr(storage, i + 1, ft_strlen(storage) - i - 1);
	free(storage);
	if (!new_storage)
		return (NULL);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage[fd] = add_storage(fd, storage[fd]);
	if (!storage[fd])
		return (NULL);
	line = ext_line(storage[fd]);
	storage[fd] = update_storage(storage[fd]);
	return (line);
}

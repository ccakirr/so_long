/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 23:57:09 by ccakir            #+#    #+#             */
/*   Updated: 2025/11/10 01:05:35 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*addstash(int fd, char *stash)
{
	int		rode;
	char	*buffer;

	if (!stash)
		stash = ft_substr("", 0, 0);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	rode = 1;
	while (!ft_strchr(stash, '\n') && rode > 0)
	{
		rode = read(fd, buffer, BUFFER_SIZE);
		if (rode < 0)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[rode] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free (buffer);
	return (stash);
}

static char	*extline(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash || !*stash)
		return (NULL);
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		line = ft_substr(stash, 0, i + 1);
	else
		line = ft_substr(stash, 0, i);
	return (line);
}

static char	*update_stash(char *stash)
{
	char	*new_stash;
	int		i;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_substr(stash, i + 1, ft_strlen(stash) - i - 1);
	free(stash);
	if (!new_stash)
		return (NULL);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = addstash(fd, stash);
	if (!stash)
		return (NULL);
	line = extline(stash);
	stash = update_stash(stash);
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 02:45:13 by ccakir            #+#    #+#             */
/*   Updated: 2025/11/29 03:00:59 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static int	is_inset(char const	c, char const	*set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const	*str, char const	*set)
{
	int		start;
	int		end;
	char	*res;

	if (!str || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(str) - 1;
	while (str[start] && (is_inset(str[start], set)))
		start++;
	while ((str[end]) && (is_inset(str[end], set)))
		end--;
	res = ft_substr(str, start, (end - start + 1));
	return (res);
}

char	**map_dup(char **map)
{
	int		len;
	int		i;
	char	**res;

	if (!map)
		return (NULL);
	len = map_len(map);
	res = malloc(sizeof(char *) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = ft_strdup(map[i]);
		if (!res[i])
		{
			while (i > 0)
				free(res[--i]);
			free(res);
			return (NULL);
		}
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	free_map(char	**map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

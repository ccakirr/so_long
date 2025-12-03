/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_01.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 02:14:22 by ccakir            #+#    #+#             */
/*   Updated: 2025/11/29 02:23:41 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_len(char	**map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	*make_all_array_zero(int *array, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		array[i] = 0;
		i++;
	}
	return (array);
}

void	error_exit(char	*msg)
{
	write(2, "Error\n", 6);
	if (!msg)
		write(2, "Unknown Error!", ft_strlen("Unknown Error!"));
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(1);
}

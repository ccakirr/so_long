/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 23:59:59 by ccakir            #+#    #+#             */
/*   Updated: 2025/11/12 23:08:41 by ccakir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
	{
		ft_printf("Error\nUsage: ./so_long <map_file.ber>\n");
		return (1);
	}
	if (!check_map(argv[1]))
		error_exit("Map is not <*.ber> format.");
	game_init(&game, argv[1]);
	return (0);
}
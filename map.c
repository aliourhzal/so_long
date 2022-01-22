/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhzal <aourhzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:27:32 by aourhzal          #+#    #+#             */
/*   Updated: 2022/01/21 12:07:03 by aourhzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw(char	*path, t_game game)
{
	void	*chr;
	int		x;
	int		y;

	x = 0;
	y = 0;
	chr = mlx_xpm_file_to_image(game.mlx_pointer, path, &x, &y);
	mlx_put_image_to_window(game.mlx_pointer, game.window, chr,
		game.window_draw.x, game.window_draw.y);
}

void	player_dir(t_game game)
{
	if (game.dir[0] == 'l')
		draw("./xpm/left-side1.xpm", game);
	else if (game.dir[0] == 'r')
		draw("./xpm/right-side1.xpm", game);
	else if (game.dir[0] == 'u')
		draw("./xpm/back1.xpm", game);
	else if (game.dir[0] == 'd')
		draw("./xpm/wall-e-front1.xpm", game);
}

void	draw_block(char block, t_game *game, int i, int j)
{
	if (block == '1')
		draw("./xpm/block.xpm", *game);
	else if (block == '0')
		draw("./xpm/ground.xpm", *game);
	else if (block == 'C')
	{
		draw("./xpm/leaf.xpm", *game);
		game->collect += 1;
	}
	else if (block == 'E')
		draw("./xpm/exit1.xpm", *game);
	else if (block == 'e')
		draw("./xpm/exit2.xpm", *game);
	else if (block == 'A')
		draw("./xpm/m-o.xpm", *game);
	else if (block == 'P')
	{
		game->pos_player.x = j;
		game->pos_player.y = i;
		player_dir(*game);
	}
}

void	map(char **map_file, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->window_draw.y = 0;
	game->collect = 0;
	while (map_file[i])
	{
		game->window_draw.x = 0;
		j = 0;
		while (map_file[i][j])
		{
			draw_block(map_file[i][j], game, i, j);
			j++;
			game->window_draw.x += 45;
		}
		game->window_draw.y += 45;
		i++;
	}
}

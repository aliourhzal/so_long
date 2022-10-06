/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elix <elix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:56:44 by aourhzal          #+#    #+#             */
/*   Updated: 2022/10/06 19:03:50 by elix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	forstpdnomr(t_game game)
{
	if (game.t_map[game.pos_player.y][game.pos_player.x] == 'e')
	{
		write(1, "you won !\n", 10);
		exit(0);
	}
	if (game.t_map[game.pos_player.y][game.pos_player.x] == 'A')
	{
		write(1, "WASTED !\n", 9);
		exit(0);
	}
}

void	redraw(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->t_map[i])
	{
		j = 0;
		while (game->t_map[i][j])
		{
			if (game->t_map[i][j] == 'P')
				game->t_map[i][j] = '0';
			if (i == game->pos_player.y && j == game->pos_player.x)
				game->t_map[i][j] = 'P';
			if (game->collect == 0 && game->t_map[i][j] == 'E')
				game->t_map[i][j] = 'e';
			forstpdnomr(*game);
			j++;
		}
		i++;
	}
}

void	directions(int keycode, t_game *game)
{
	if (keycode == 13 || keycode == 126)
	{
		game->pos_player.y -= 1;
		game->dir = "up";
	}
	if (keycode == 1 || keycode == 125)
	{
		game->pos_player.y += 1;
		game->dir = "down";
	}
	if (keycode == 0 || keycode == 123)
	{
		game->pos_player.x -= 1;
		game->dir = "left";
	}
	if (keycode == 2 || keycode == 124)
	{
		game->pos_player.x += 1;
		game->dir = "right";
	}
}

int	player_moves(int keycode, t_game *game)
{
	if (keycode == 53)
		exit(0);
	directions(keycode, game);
	if (game->t_map[game->pos_player.y][game->pos_player.x] != '1' &&
		game->t_map[game->pos_player.y][game->pos_player.x] != 'E')
		redraw(game);
	map(game->t_map, game);
	return (0);
}

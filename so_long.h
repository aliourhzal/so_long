/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhzal <aourhzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:27:28 by aourhzal          #+#    #+#             */
/*   Updated: 2022/01/21 19:06:57 by aourhzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx.h"
# include "./get_next_line/get_next_line.h"

typedef struct dimensions
{
	int	x;
	int	y;
}	t_dimensions;

typedef struct s_game
{
	void			*window;
	void			*mlx_pointer;
	char			**t_map;
	t_dimensions	window_draw;
	t_dimensions	pos_player;
	int				collect;
	char			*dir;
}	t_game;

void	map(char **map_file, t_game *game);
void	draw(char *path, t_game game);
int		player_moves(int keycode, t_game *game);
char	**ft_split(const char *s, char c);
void	map_checker(char **map);
void	extension_checker(char	*path);

#endif
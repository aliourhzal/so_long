/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhzal <aourhzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:09:55 by aourhzal          #+#    #+#             */
/*   Updated: 2022/01/21 19:58:57 by aourhzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>

int	ft_close(int key)
{
	(void)key;
	exit(0);
}

void	extension_checker(char	*path)
{
	int	len;
	
	len = 0;
	while(path[len])
		len++;
	if (path[len - 1] != 'r' || path[len - 2] != 'e' ||
		path[len - 3] != 'b' || path[len - 4] != '.')
	{
		write(1, "the map xtension should be '.ber'\n", 34);
		exit(0);
	}	
}

void	win_dim(char  *path, t_dimensions *window_size)
{
	int				fd;
	char			*line;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	window_size->x = ft_strlen(line) - 1;
	window_size->y = 0;
	while (line)
	{
		window_size->y++;
		line = get_next_line(fd);
	}
	close(fd);
}

char	**split_map(char *map_path)
{
	char	**t_map;
	char	*line_map;
	char	*line;
	int		fd;

	fd = open(map_path, O_RDONLY);
	line_map = get_next_line(fd);
	line = get_next_line(fd);
	while (line)
	{
		line_map = ft_strjoin(line_map, line);
		line = get_next_line(fd);
	}
	t_map = ft_split(line_map, '\n');
	return (t_map);
}

int	main(int ac, char **av)
{
	t_game			game;
	t_dimensions	window_size;

	if (ac == 2)
	{
		extension_checker(av[1]);	
		game.t_map = split_map(av[1]);
		map_checker(game.t_map);
		win_dim(av[1], &window_size);
		game.mlx_pointer = mlx_init();
		game.window = mlx_new_window(game.mlx_pointer, window_size.x * 45,
				window_size.y * 45, "Wall-E");
		game.dir = "down";
		mlx_hook(game.window, 17, 0, ft_close, 0);
		map(game.t_map, &game);
		mlx_key_hook(game.window, player_moves, &game);
		mlx_loop(game.mlx_pointer);
	}
	else
		write(1, "Error: so_long needs the map\n", 29);
}

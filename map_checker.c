/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhzal <aourhzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:21:38 by aourhzal          #+#    #+#             */
/*   Updated: 2022/01/21 20:10:58 by aourhzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	components_counter(char **map)
{
	int	i;
	int	j;
	int	c;
	int	e;
	
	i = -1;
	c = 0;
	e = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				c++;
			if (map[i][j] == 'E')
				e++;
		}
	}
	if (e == 0 || c == 0)
	{
		write(1, "the map should contain at least one collectible and one  map exit\n", 66);
		exit(1);
	}
}

int	components_checker(char **map)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while(map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '1' && map[i][j] != 'C' && map[i][j] != 'P'
				&& map[i][j] != 'E' && map[i][j] != 'A' && map[i][j] != '0')
			{
				printf("the charachter '%c' is not supported", map[i][j]);
				exit(1);
			}
			if (map[i][j] == 'P')
					count++;
		}
	}
	components_counter(map);
	return (count);
}

void	ceiling_ground(char **map, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i <= height - 1)
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '1')
			{
				write(1, "the map should surrounded by walls (1)\n", 39);
				exit(1);
			}
		}
		i += height - 1;
	}
}

void	wall_checker(char **map, int lenth, int height)
{
	int	i;

	i = 0;
	ceiling_ground(map, height);
	while (++i < height - 1)
	{
		if (map[i][0] != '1' || map[i][lenth - 1] != '1')
		{
			write(1, "the map should surrounded by walls (1)\n", 39);
			exit(1);
		}
	}
}

void	map_checker(char **map)
{
	int	lenth;
	int	height;
	int	i;

	i = 0;
	height = 0;
	lenth = ft_strlen(map[i]);
	while (map[height])
		height++;
	while (map[i])
	{
		if (lenth != ft_strlen(map[i]))
		{
			write(1, "The map must be rectangular\n", 28);
			exit(1);
		}
		i++;
	}
	wall_checker(map, lenth, height);
	if (components_checker(map) != 1)
	{
		write(1, "you must have one player 'P' in your map\n", 41);
		exit(1);
	}
}

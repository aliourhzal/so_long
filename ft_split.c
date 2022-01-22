/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhzal <aourhzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:03:09 by aourhzal          #+#    #+#             */
/*   Updated: 2022/01/18 19:03:22 by aourhzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "so_long.h"

static int	countword(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static int	countchr(const char *s, char c, int start)
{
	int	i;

	i = 0;
	while (s[start])
	{
		if (s[start] == c)
			break ;
		i++;
		start++;
	}
	return (i);
}

static void	cpy(char **str, const char *s, char c, int nbrw)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	x = 0;
	while (i < nbrw)
	{
		j = 0;
		while (s[x] == c)
			x++;
		while (s[x] && s[x] != c)
		{
			str[i][j] = s[x];
			x++;
			j++;
		}
		str[i][j] = 0;
		i++;
	}
	str[i] = 0;
}

static char	**freal(char **str)
{
	int	i;

	i = 0;
	while (str)
	{
		free(str[i]);
		i++;
	}
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**str;
	int		is;
	int		i;

	i = 0;
	if (s)
	{
		is = 0;
		str = malloc(countword(s, c) * sizeof(char *) + 1);
		if (str == NULL)
			return (0);
		while (i < countword(s, c))
		{
			while (s[is] == c)
				is++;
			str[i++] = (char *)malloc(countchr(s, c, is) * sizeof(char) + 1);
			if (!str[i - 1])
				return (freal(str));
			is += countchr(s, c, is);
		}
		cpy(str, s, c, countword(s, c));
		return (str);
	}
	return (0);
}

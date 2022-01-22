/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhzal <aourhzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 21:11:19 by aourhzal          #+#    #+#             */
/*   Updated: 2022/01/21 16:05:08 by aourhzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*overflow(char *over)
{
	int		i;
	int		x;
	char	*s;

	i = 0;
	x = 0;
	if (over[0] == '\0')
	{
		free(over);
		return (NULL);
	}
	while (over[i] != '\n' && over[i] != '\0')
		i++;
	if (over[i] == '\n')
		i++;
	s = malloc((ft_strlen(over) - i) * sizeof(char) + 1);
	if (!s)
		return (NULL);
	while (over[i] != '\0')
		s[x++] = over[i++];
	s[x] = '\0';
	free(over);
	return (s);
}

static char	*main_str(char *over)
{
	int		i;
	char	*str;

	i = 0;
	if (over[0] == '\0')
		return (NULL);
	while (over[i] != '\n' && over[i] != '\0')
		i++;
	if (over[i] == '\n')
		i++;
	str = malloc(i * sizeof(char) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (over[i] != '\n' && over[i] != '\0')
	{
		str[i] = over[i];
		i++;
	}
	if (over[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

static char	*ms_n_over(int fd, char *over)
{
	char	*buff;
	int		rc;

	buff = malloc((5 + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rc = 1;
	while (!ft_strchr(over, '\n') && rc != 0)
	{
		rc = read(fd, buff, 5);
		if (rc == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rc] = '\0';
		over = ft_strjoin(over, buff);
	}
	free(buff);
	return (over);
}

char	*get_next_line(int fd)
{
	static char	*over;
	char		*ms;

	if (fd < 0)
		return (NULL);
	over = ms_n_over(fd, over);
	if (!over)
		return (NULL);
	ms = main_str(over);
	over = overflow(over);
	return (ms);
}

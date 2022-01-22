/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhzal <aourhzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 21:11:24 by aourhzal          #+#    #+#             */
/*   Updated: 2022/01/21 16:07:25 by aourhzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int 	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);

#endif
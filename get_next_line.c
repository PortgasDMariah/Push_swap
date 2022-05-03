/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:38:36 by mdouiri           #+#    #+#             */
/*   Updated: 2022/04/27 14:44:46 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
#include <stddef.h>

char	*ft_strdup(char *str)
{
	char	*new_str;
	int		len;
	int		i;

	i = -1;
	len = 0x0;
	while (str[len])
		len++;
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (0x0);
	while (++i < len)
		new_str[i] = str[i];
	new_str[i] = 0x0;
	return (new_str);
}

char	*get_next_line(int fd)
{
	char	heap[100];
	char	buff;
	int		nbyte;
	int		i;

	nbyte = 0x0;
	i = 0x0;
	if (fd < 0x0)
		return (0);
	nbyte = read(fd, &buff, 0x1);
	while (nbyte > 0x0)
	{
		heap[i++] = buff;
		if (buff == '\n')
			break ;
		nbyte = read(fd, &buff, 0x1);
	}
	heap[i] = '\0';
	if (nbyte <= 0x0 && i == 0x0)
		return (0x0);
	return (ft_strdup(heap));
}

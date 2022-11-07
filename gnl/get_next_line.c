/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:07:11 by ktang             #+#    #+#             */
/*   Updated: 2022/06/03 19:06:27 by ktang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*storage[FOPEN_MAX];
	char		*line;
	int			byte_read;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	while (!ft_get_eol(&storage[fd][0]))
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == 0)
			break ;
		buffer[byte_read] = '\0';
		storage[fd] = ft_join_string(storage[fd], buffer);
	}
	free(buffer);
	if (!storage[fd])
		return (NULL);
	line = ft_get_line(&storage[fd], ft_get_eol(storage[fd]));
	storage[fd] = ft_next_line(&storage[fd]);
	return (line);
}
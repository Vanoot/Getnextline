/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvan-oot <cvan-oot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:13:04 by cvan-oot          #+#    #+#             */
/*   Updated: 2023/03/29 16:53:07 by cvan-oot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
	{
		i++;
	}
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}
char	*read_file(int fd, char *buffer)
{
	char	*buff;
	int		readed_byte;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	buff = ft_calloc(BUFFERSIZE + 1, sizeof(char));
	readed_byte = 1;
	while (readed_byte> 0)
	{
		readed_byte = read(fd, buff, BUFFERSIZE);
		if (readed_byte == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[readed_byte] = 0;
		buffer = joinfree(buffer, buff);
		if (strchr(buff, '\n'))
			break;
	}
	free(buff);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*current_line;

	if (fd < 0 || BUFFER_SIZE <=0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	current_line = get_line(buffer);
	buffer = next(buffer);
	return (current_line);
}

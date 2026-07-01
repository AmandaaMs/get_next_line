/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoura-d <amoura-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 16:23:13 by amoura-d          #+#    #+#             */
/*   Updated: 2026/07/01 08:41:32 by amoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_and_accumulate(int fd, char *static_buffer);
char	*extract_line(char *static_buffer);
char	*update_storage(char *static_buffer);

char	*get_next_line(int fd)
{
	static char	*storage[FD_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FD_MAX)
		return (NULL);
	storage[fd] = read_and_accumulate(fd, storage[fd]);
	if (!storage[fd])
		return (NULL);
	line = extract_line(storage[fd]);
	storage[fd] = update_storage(storage[fd]);
	return (line);
}

char	*read_and_accumulate(int fd, char *static_buffer)
{
	char	*buffer;
	int		count;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	count = 1;
	while (!ft_strchr(static_buffer, '\n') && count != 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
		{
			free(buffer);
			free(static_buffer);
			return (NULL);
		}
		buffer[count] = '\0';
		static_buffer = ft_strjoin(static_buffer, buffer);
	}
	free(buffer);
	return (static_buffer);
}

char	*extract_line(char *static_buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!static_buffer || static_buffer[0] == '\0')
		return (NULL);
	while (static_buffer[i] && static_buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (static_buffer[i] && static_buffer[i] != '\n')
	{
		line[i] = static_buffer[i];
		i++;
	}
	if (static_buffer[i] == '\n')
	{
		line[i] = static_buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*update_storage(char *static_buffer)
{
	int		i;
	int		j;
	char	*new_storage;

	i = 0;
	while (static_buffer[i] && static_buffer[i] != '\n')
		i++;
	if (!static_buffer[i])
	{
		return (free(static_buffer), NULL);
	}
	new_storage = malloc(sizeof(char) * (ft_strlen(static_buffer) - i + 1));
	if (!new_storage)
		return (NULL);
	i++;
	j = 0;
	while (static_buffer[i])
	{
		new_storage[j] = static_buffer[i];
		i++;
		j++;
	}
	new_storage[j] = '\0';
	free(static_buffer);
	return (new_storage);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:40:05 by mchihab           #+#    #+#             */
/*   Updated: 2023/12/07 14:45:14 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_reader_line(char *buffer)
{
	int		i;
	char	*line;

	if (!buffer || !buffer[0])
		return (0);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (0);
	i = -1;
	while (buffer[++i] && buffer[i] != '\n')
		line[i] = buffer[i];
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_move_buffer(char *buffer)
{
	char	*new_buf;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	i += (buffer[i] == '\n');
	new_buf = malloc(1 + ft_strlen(buffer) - i);
	if (!new_buf)
		return (NULL);
	j = -1;
	while (buffer[i + (++j)])
		new_buf[j] = buffer[i + j];
	new_buf[j] = '\0';
	free(buffer);
	return (new_buf);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	int			reader;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reader = 1;
	tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	while (!(ft_strchr(buffer[fd], '\n')) && reader != 0)
	{
		reader = read(fd, tmp, BUFFER_SIZE);
		if (reader == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[reader] = '\0';
		buffer[fd] = ft_strjoin(buffer[fd], tmp);
	}
	free(tmp);
	tmp = ft_reader_line(buffer[fd]);
	buffer[fd] = ft_move_buffer(buffer[fd]);
	return (tmp);
}

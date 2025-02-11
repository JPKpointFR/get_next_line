/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adcisse <adcisse@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-10 12:22:45 by adcisse           #+#    #+#             */
/*   Updated: 2024-11-10 12:22:45 by adcisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char **stash)
{
	int		len;
	char	*line;
	int		i;

	len = 0;
	while ((*stash)[len] && (*stash)[len] != '\n')
		len++;
	if ((*stash)[len] == '\n')
		len++;
	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = -1;
	while (++i < len)
		line[i] = (*stash)[i];
	line[i] = '\0';
	return (line);
}

static void	clear_stash(char **stash)
{
	int		len;
	char	*temp;

	len = 0;
	while ((*stash)[len] && (*stash)[len] != '\n')
		len++;
	if ((*stash)[len] == '\0')
	{
		free(*stash);
		*stash = NULL;
	}
	else
	{
		temp = ft_strdup(&(*stash)[len + 1]);
		free(*stash);
		*stash = temp;
	}
}

static char	*read_line(int fd, char **stash)
{
	char		*buffer;
	char		*new_stash;
	int			bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		new_stash = ft_strjoin(*stash, buffer);
		free(*stash);
		*stash = new_stash;
		if (!*stash)
		{
			free(buffer);
			return (NULL);
		}
		if (ft_strchr(*stash, '\n'))
			break ;
		bytes = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (*stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!read_line(fd, &stash))
		return (NULL);
	if (!stash || stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = extract_line(&stash);
	clear_stash(&stash);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*get;

// 	fd = open("a.txt", O_RDONLY);
// 	if (fd == -1)
// 		printf("fd\n");
// 	else
// 	{
// 		get = get_next_line(fd);
// 		while (get)
// 		{
// 			printf("%s", get);
// 			free(get);
// 			get = get_next_line(fd);
// 		}
// 		printf("%s", get);
// 	}
// 	close(fd);
// 	return (0);
// }

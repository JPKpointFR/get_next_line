/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adcisse <adcisse@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-12 22:16:59 by adcisse           #+#    #+#             */
/*   Updated: 2024-11-12 22:16:59 by adcisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	lenght;

	lenght = 0;
	if (str)
	{
		while (str[lenght] != '\0')
			lenght++;
	}
	return (lenght);
}

t_fd_node	*ft_lstnew(int fd, t_fd_node **front)
{
	t_fd_node	*mall;

	mall = malloc(sizeof(t_fd_node));
	if (!mall)
		return (NULL);
	mall->fd = fd;
	mall->stash = NULL;
	mall->next = *front;
	// printf("er %s\n", (char*)*front);
	return (mall);
}

char	*ft_strchr(const char *s, int c)
{
	char	*string;
	int		i;

	i = 0;
	string = (char *)s;
	while (string[i] != (char)c && string[i])
		i++;
	if (string[i] == (char)c)
		return (&string[i]);
	else
		return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*mall;
	int		i;

	mall = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!mall)
		return (NULL);
	i = 0;
	while (s[i])
	{
		mall[i] = s[i];
		i++;
	}
	mall[i] = '\0';
	return (mall);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mall;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	mall = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!mall)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		mall[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		mall[i + j] = s2[j];
		j++;
	}
	mall[i + j] = '\0';
	return (mall);
}

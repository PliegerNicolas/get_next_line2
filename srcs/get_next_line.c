/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:13:39 by nplieger          #+#    #+#             */
/*   Updated: 2023/01/17 11:56:47 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*buffer_join(char *rem, char *buffer)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!rem)
	{
		rem = malloc(sizeof(char));
		rem[0] = 0;
	}
	if (!rem || !buffer)
		return (NULL);
	new = malloc((ft_strlen(rem) + ft_strlen(buffer) + 1) * sizeof(*new));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	if (rem)
		while (rem[i])
			new[i++] = rem[j++];
	j = 0;
	while (buffer[j])
		new[i++] = buffer[j++];
	new[i] = 0;
	free(rem);
	return (new);
}

static char	*read_fd_until_nl(const int fd, char *remaining)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(*buffer));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (read_bytes && !ft_strchr(remaining, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = 0;
		remaining = buffer_join(remaining, buffer);
	}
	free(buffer);
	return (remaining);
}

static char	*retrieve_line(char *rem, size_t *endl)
{
	char	*new;
	size_t	i;

	if (!rem[*endl])
		return (NULL);
	while (rem[*endl] && rem[*endl] != '\n')
		(*endl)++;
	new = malloc((*endl + 2) * sizeof(*new));
	if (!new)
		return (NULL);
	i = 0;
	while (i < *endl)
	{
		new[i] = rem[i];
		i++;
	}
	if (rem[i] == '\n')
	{
		new[i] = rem[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

static char	*split_remaining(char *rem, size_t endl)
{
	char	*new;
	size_t	i;
	size_t	nl_found;

	if (!rem[endl])
	{
		free(rem);
		return (NULL);
	}
	nl_found = contains_nl(rem, endl);
	new = malloc((ft_strlen(rem) - endl + nl_found + 1) * sizeof(*new));
	if (!new)
		return (NULL);
	endl++;
	i = 0;
	while (rem[endl])
		new[i++] = rem[endl++];
	new[i] = 0;
	free(rem);
	return (new);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*remaining;
	size_t			endl;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	remaining = read_fd_until_nl(fd, remaining);
	if (!remaining)
		return (NULL);
	endl = 0;
	line = retrieve_line(remaining, &endl);
	remaining = split_remaining(remaining, endl);
	return (line);
}

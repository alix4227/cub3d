/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrusoe <acrusoe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:44:35 by acrusoe           #+#    #+#             */
/*   Updated: 2025/04/08 14:44:35 by acrusoe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

char	*fill_line(char *buffer, char *left_char, int fd)
{
	ssize_t	read_line;
	char	*temp;

	read_line = 1;
	if (!left_char)
		left_char = ft_strdup("");
	while (read_line > 0)
	{
		read_line = read(fd, buffer, BUFFER_SIZE);
		if (read_line == -1)
			return (NULL);
		else if (read_line == 0)
			break ;
		buffer[read_line] = '\0';
		temp = left_char;
		left_char = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(left_char) != 0)
			break ;
	}
	free(buffer);
	return (left_char);
}

char	*ft_get_line(char *retour, char *line, char *left_char)
{
	int	i;

	i = 0;
	retour = malloc((ft_strlen(line) - ft_strlen(left_char) + 1)
			* sizeof(char));
	if (!retour)
	{
		free (line);
		return (0);
	}
	while (line[i] != '\n' && line[i] != '\0')
	{
		retour[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		retour[i] = '\n';
		retour[i + 1] = '\0';
	}
	else
		retour[i] = '\0';
	free (line);
	return (retour);
}

char	*ft_return(char *line, char *left_char)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	i++;
	left_char = malloc((ft_strlen(line) - i + 1) * sizeof(char));
	if (!left_char)
		return (NULL);
	while (line[i] != '\0')
	{
		left_char[j] = line[i];
		i++;
		j++;
	}
	left_char[j] = '\0';
	return (left_char);
}

char	*ft_malloc(int n)
{
	char	*buffer;

	buffer = malloc((n + 1) * sizeof(char));
	if (!buffer)
		return (0);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*retour;
	int			n;
	char		*line;
	static char	*left_char = NULL;

	n = BUFFER_SIZE;
	retour = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free (left_char);
		left_char = NULL;
		return (NULL);
	}
	buffer = ft_malloc(n);
	line = fill_line(buffer, left_char, fd);
	left_char = ft_return(line, left_char);
	if (line[0] == '\0')
	{
		free(left_char);
		free(line);
		return (NULL);
	}
	return (ft_get_line(retour, line, left_char));
}

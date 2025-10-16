/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cardinal_lines.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekido <gekido@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:21:55 by acrusoe           #+#    #+#             */
/*   Updated: 2025/10/12 00:51:55 by gekido           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ids2(char **id)
{
	id[0] = "NO";
	id[1] = "SO";
	id[2] = "WE";
	id[3] = "EA";
	id[4] = "F";
	id[5] = "C";
}

char	*get_line(const char *str)
{
	char	*s;
	int		j;
	int		i;

	i = 0;
	j = 0;
	s = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while (str[i] && str[i] != '\n' && str[i] != '\r')
	{
		s[j] = str[i];
		j++;
		i++;
	}
	s[j] = '\0';
	return (s);
}

int	ft_check_path(const char *file)
{
	int		fd;
	char	*str;

	str = get_line(file);
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		free(str);
		return (0);
	}
	free(str);
	close(fd);
	return (1);
}

int	ft_check_cardinal_line(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0 ;
	while (s1[i] == s2[i] && i < n && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (s1[i] != s2[i])
		return (0);
	i++;
	while (s1[i] && is_whitespace(s1[i]))
		i++;
	if (s1[i] && strncmp(&s1[i], "./", 2) == 0)
	{
		if (ft_check_path(&s1[i]))
			return (1);
	}
	return (0);
}

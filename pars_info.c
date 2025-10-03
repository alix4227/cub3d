/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrusoe <acrusoe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:45:48 by acrusoe           #+#    #+#             */
/*   Updated: 2025/10/03 14:45:48 by acrusoe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

int	check_range(int *nb)
{
	int	i;

	i = 0;
	if (!nb)
		return (0);
	while (i < 3)
	{
		if (nb[i] < 0 || nb[i] > 255)
			return (0);
		i++;
	}
	return (1);
}

int	check_char(char *str)
{
	int	i;
	int	digit;

	i = 0;
	digit = 0;
	if (!str)
		return (0);
	while (is_whitespace(str[i]))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = 1;
		i++;
	}
	while (is_whitespace(str[i]))
		i++;
	if (digit && str[i] == '\0')
		return (1);
	return (0);
}

int	get_nb(const char *str, char *s, int *nb, int i)
{
	int		j;
	int		k;

	k = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] && str[i] != ',')
		{
			s[j++] = str[i++];
		}
		s[j] = '\0';
		if (!check_char(s))
			return (0);
		if (k >= 3)
			return (0);
		nb[k++] = atoi(s);
		if (str[i] == '\0')
			break ;
		i++;
	}
	return (1);
}

int	check_numbers(const char *str)
{
	int		nb[1000];
	char	s[1000000];
	int		i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	if (!get_nb(str, s, nb, i))
		return (0);
	if (check_range(nb))
		return (1);
	return (0);
}

int	ft_check_id_nb(const char *s1, const char *s2, size_t n)
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
	if (check_numbers(&s1[i]))
		return (1);
	return (0);
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
		perror("Wrong Path");
		free(str);
		return (0);
	}
	free(str);
	close(fd);
	return (1);
}

int	ft_check_id(const char *s1, const char *s2, size_t n)
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

void	ft_count_id(t_data *game, char *str)
{
	if (strcmp(str, "NO") == 0)
		game->no++;
	else if (strcmp(str, "SO") == 0)
		game->so++;
	else if (strcmp(str, "WE") == 0)
		game->we++;
	else if (strcmp(str, "EA") == 0)
		game->ea++;
	else if (strcmp(str, "F") == 0)
		game->f++;
	else if (strcmp(str, "C") == 0)
		game->c++;
}

static void	init_ids2(char **id)
{
	id[0] = "NO";
	id[1] = "SO";
	id[2] = "WE";
	id[3] = "EA";
	id[4] = "F";
	id[5] = "C";
}

int	check_lines2(char *line, char **id, int j, t_data *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (ft_check_id(&line[j], id[i], 1))
		{
			ft_count_id(game, id[i]);
			return (1);
		}
		if (i > 3 && ft_check_id_nb(line, id[i], 0))
		{
			ft_count_id(game, id[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_line(t_data *game, char *line)
{
	int		j;
	char	*id[6];

	j = 0;
	init_ids2(id);
	while (is_whitespace(line[j]))
		j++;
	if (line[j] == '\0')
		return (1);
	if (check_lines2(line, id, j, game))
		return (1);
	return (0);
}

static void	init_doublons(int *doublons, t_data *game)
{
	doublons[0] = game->no;
	doublons[1] = game->so;
	doublons[2] = game->we;
	doublons[3] = game->ea;
	doublons[4] = game->f;
	doublons[5] = game->c;
}

int	check_doubles(t_data *game)
{
	int	doublons[6];
	int	i;

	i = 0;
	init_doublons(doublons, game);
	while (i < 6)
	{
		if (doublons[i] != 1)
			return (0);
		i++;
	}
	return (1);
}

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (is_whitespace(line[i]))
		i++;
	if (line[i] == '0' || line[i] == '1')
		return (1);
	return (0);
}

int	parsing_info(t_data *game, char *file)
{
	char	*line;
	int		map;

	map = open(file, O_RDONLY);
	line = get_next_line(map);
	while (line != NULL)
	{
		if (is_map_line(line))
			break ;
		if (!check_line(game, line))
		{
			free(line);
			get_next_line(-1);
			return (0);
		}
		free(line);
		line = get_next_line(map);
	}
	close(map);
	free(line);
	get_next_line(-1);
	if (!check_doubles(game))
		return (0);
	return (1);
}

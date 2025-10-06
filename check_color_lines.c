/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color_lines.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrusoe <acrusoe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:25:31 by acrusoe           #+#    #+#             */
/*   Updated: 2025/10/06 15:32:09 by acrusoe          ###   ########.fr       */
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

int	ft_check_color_nb(const char *s1, const char *s2, size_t n)
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

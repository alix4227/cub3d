/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrusoe <acrusoe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:44:13 by acrusoe           #+#    #+#             */
/*   Updated: 2025/04/08 14:44:13 by acrusoe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(char *left_char)
{
	int		i;
	char	n;

	n = '\n';
	i = 0;
	while (left_char[i] != '\0')
	{
		if (left_char[i] == n)
		{
			i++;
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1);
	str = malloc((len + 1) * sizeof(char));
	i = 0;
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strcat(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str1;
	int		len1;
	int		len2;

	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str1 = malloc((len1 + len2 + 1) * sizeof(char));
	if (!str1 || !s1 || !s2)
		return (NULL);
	while (s1[i] != '\0')
	{
		str1[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		str1[i++] = s2[j++];
	str1[i] = '\0';
	return (str1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strcat;

	strcat = ft_strcat(s1, s2);
	return (strcat);
}

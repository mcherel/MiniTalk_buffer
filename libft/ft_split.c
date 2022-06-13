/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherel- <mcherel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:18:21 by mcherel-          #+#    #+#             */
/*   Updated: 2022/06/13 10:41:25 by mcherel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_nb_unit(char const *s, char c);
static char			**ft_strndup(char **tab, char const *s, char c, int n);
static char			**ft_clear(char **tab);

char	**ft_split(char const *s, char c)
{
	char			**tab;
	unsigned int	tab_len;

	if (!s)
		return (NULL);
	tab_len = ft_nb_unit(s, c);
	tab = ft_calloc((tab_len + 1), sizeof(char *));
	if (!tab)
		return (NULL);
	tab = ft_strndup(tab, s, c, tab_len);
	return (tab);
}

static unsigned int	ft_nb_unit(char const *s, char c)
{
	unsigned int	unit;
	unsigned int	i;

	i = 0;
	unit = 0;
	while (s[i])
	{
		if (s[i] != c && i == 0)
			unit++;
		if (i > 0 && s[i - 1] == c && s[i] != c)
			unit++;
		i++;
	}
	return (unit);
}

static char	**ft_strndup(char **tab, char const *s, char c, int n)
{
	int	i;
	int	start;
	int	count;

	i = 0;
	start = 0;
	count = 0;
	while (s[start] && i < n)
	{
		while (s[start] == c)
			start++;
		while (s[start] != c && s[start])
		{
			start++;
			count++;
		}
		tab[i] = malloc(sizeof(char) * count + 1);
		if (!tab)
			return (ft_clear(tab));
		ft_strlcpy(tab[i], &s[start - count], count + 1);
		count = 0;
		i++;
	}
	return (tab);
}

static char	**ft_clear(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

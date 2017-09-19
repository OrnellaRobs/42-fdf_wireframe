/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_get_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:36:28 by orazafin          #+#    #+#             */
/*   Updated: 2017/09/20 00:28:01 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdfhead.h"

static int		how_many_column(char *line)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	count = 0;
	flag = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			flag = 0;
		else if (line[i] != ' ' && flag == 0)
		{
			count++;
			flag = 1;
		}
		i++;
	}
	return (count);
}

static char 	**parsing(int fd, t_set *setting)
{
	char	*line;
	char	**tab;
	int		nb_column;
	int		i;

	i = 0;
	if (!(tab = malloc(sizeof(char *) * SIZE_MAXI)))
		return (NULL);
	while (get_next_line(fd, &line))
	{
		if (!(tab[i] = malloc(sizeof(char) * SIZE_MAXI)))
			return (NULL);
		nb_column = how_many_column(line);
		if (nb_column > setting->column_max)
			setting->column_max = nb_column;
		tab[i] = line;
		i++;
	}
	tab[i] = NULL;
	setting->line = i;
	return (tab);
}

static int		*convert_line_into_int_tab(int *map, char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		map[i] = ft_atoi(split[i]);
		i++;
	}
	return (map);
}

static int		*initialize_tab_with_zero(int *map, t_set *setting)
{
	int j;

	j = 0;
	while (j < setting->column_max)
	{
		map[j] = 0;
		j++;
	}
	return (map);
}

int				**get_map(int fd, t_set *setting)
{
	char	**first_tab;
	int		**final_tab;
	char	**split;
	int		i;

	i = 0;
	first_tab = parsing(fd, setting);
	if (!(final_tab = malloc(sizeof(int *) * setting->line + 1)))
		return (NULL);
	while (first_tab[i])
	{
		if (!(final_tab[i] = malloc(sizeof(int) * setting->column_max)))
			return (NULL);
		split = ft_strsplit(first_tab[i], ' ');
		if (check_valid_map(split) == 1)
			return (NULL);
		final_tab[i] = initialize_tab_with_zero(final_tab[i], setting);
		final_tab[i] =  convert_line_into_int_tab(final_tab[i], split);
		i++;
	}
	final_tab[i] = NULL;
	setting->column = setting->column_max;
	free_first_tab(first_tab);
	return (final_tab);
}

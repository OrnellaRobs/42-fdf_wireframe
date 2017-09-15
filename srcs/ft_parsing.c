/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 10:20:23 by orazafin          #+#    #+#             */
/*   Updated: 2017/09/13 15:17:56 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdfhead.h"

static int      get_number_column(char *line)
{
	int i;
	int count;
	int flag;

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

static int      *convert_line_into_int_tab(int *map, char **split, int column)
{
	int i;

	i = 0;
	while (split[i])
	{
		map[i] = ft_atoi(split[i]);
		i++;
	}
	i = 0;
	while (i < column)
	{
		printf("%d ", map[i]);
		i++;
	}
	printf("\n");
	return (map);
}

static int		*initialize_tab_with_zero(int *map, int nb_column)
{
	int j;

	j = 0;
	while (j < nb_column)
	{
		map[j] = 0;
		j++;
	}
	return (map);
}

int			    **get_map(int fd, t_set *setting)
{
	char	*line;
	int		**map;
	char	**split;
	int		i;
	int		nb_column;

	i = 0;
	if (!(map = malloc(sizeof(int *) * SIZE_MAXI * 2)))
		return (NULL);
	while (get_next_line(fd, &line))
	{
		nb_column = get_number_column(line);
		setting->column = nb_column;
		if (!(map[i] = malloc(sizeof(int) * nb_column)))
			return (NULL);
		split = ft_strsplit(line, ' ');
		map[i] = initialize_tab_with_zero(map[i], nb_column);
		map[i] = convert_line_into_int_tab(map[i], split, nb_column);
		i++;
	}
	map[i] = NULL;
	setting->line = i;
	return (map);
}

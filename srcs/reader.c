/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 13:57:10 by rsmith            #+#    #+#             */
/*   Updated: 2019/09/10 15:17:55 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_map		*get_map(int width, int height)
{
	t_map	*map;

	map = ft_memalloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->width = width;
	map->height = height;
	map->points = ft_memalloc(sizeof(t_point*) * width * height + 1);
	if (map->points == NULL)
	{
		ft_memdel((void**)&map);
		return (NULL);
	}
	map->points[width * height] = NULL;
	return (map);
}

static int	cleanup(t_list **list, t_map **map)
{
	t_list *next;

	while (*list)
	{
		next = (*list)->next;
		ft_memdel(&(*list)->content);
		ft_memdel((void**)list);
		*list = next;
	}
	if (map && *map)
	{
		ft_memdel((void **)&(*map)->points);
		ft_memdel((void **)map);
	}
	return (0);
}

static int	get_lines(int fd, t_list **list)
{
	t_list	*tmp;
	int		expected;
	char	*line;
	int		ret;

	expected = -1;
	while ((ret = get_next_line(fd, &line)))
	{
		if (expected == -1)
			expected = (int)ft_wordcount(line, ' ');
		tmp = ft_lstnew(line, ft_strlen(line) + 1);
		if (tmp == NULL)
			return (cleanup(list, NULL));
		ft_lstadd(list, tmp);
		if (expected != (int)ft_wordcount(line, ' '))
			return (cleanup(list, NULL));
		ft_strdel(&line);
	}
	if (expected == -1 || ret == -1)
		return (cleanup(list, NULL));
	ft_lstrev(list);
	return (1);
}

static int	populate_map(t_list *lst, t_map **map)
{
	t_list	*tmp;
	char	**split;
	int		x;
	int		y;

	tmp = lst;
	y = 0;
	while (y < (*map)->height)
	{
		x = 0;
		if (!(split = ft_strsplit(tmp->content, ' ')))
			return (cleanup(&lst, map));
		while (x < (*map)->width)
		{
			(*map)->points[y * (*map)->width + x] =
				set_point(*map, x, y, split[x]);
			x++;
		}
		ft_splitdel(&split);
		tmp = tmp->next;
		y++;
	}
	cleanup(&lst, NULL);
	return (1);
}

int			read_file(int fd, t_map **map)
{
	t_list *list;

	list = NULL;
	if (!(get_lines(fd, &list)))
		return (0);
	*map = get_map(ft_wordcount(list->content, ' '), ft_lstcount(list));
	close(fd);
	if (map == NULL)
		return (cleanup(&list, map));
	return (populate_map(list, map));
}

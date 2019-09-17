/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:53:59 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/03/04 16:59:34 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*get_file(const int fd, t_list **file)
{
	t_list	*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}

static void			clean(t_list *ptr)
{
	char *tmp;

	if ((tmp = ft_strchr(ptr->content, '\n')))
	{
		tmp = ft_strdup(tmp + 1);
		free(ptr->content);
		ptr->content = tmp;
	}
	else
		ft_strclr(ptr->content);
}

int					get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	static t_list	*file;
	t_list			*ptr;
	int				readboi;

	ERROR_CHECK(fd < 0 || line == NULL || read(fd, buf, 0) < 0);
	ptr = get_file(fd, &file);
	while ((readboi = read(fd, buf, BUFF_SIZE)))
	{
		buf[readboi] = '\0';
		ERROR_CHECK(!(tmp = ft_strjoin(ptr->content, buf)));
		free(ptr->content);
		ptr->content = tmp;
		BREAK_CHECK(ft_strchr(ptr->content, '\n'));
	}
	if (!readboi && !ft_strlen(ptr->content))
	{
		ft_strclr(*line);
		return (0);
	}
	ERROR_CHECK(!(*line = ft_strnew(ft_strlen(ptr->content))));
	*line = ft_strccpy(*line, ptr->content, '\n');
	clean(ptr);
	return (1);
}

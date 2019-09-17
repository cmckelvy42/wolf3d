/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:56:29 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/03/14 12:47:45 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 68
# define ERROR_CHECK(x) if (x) return (-1)
# define BREAK_CHECK(x) if (x) break

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int		get_next_line(const int fd, char **line);

#endif

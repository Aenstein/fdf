/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:23:54 by aenstein          #+#    #+#             */
/*   Updated: 2019/10/13 17:33:49 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_write_in_line(char **fd_ukaz, char **line, int fd)
{
	int				i;
	char			*tmp;

	i = 0;
	while (fd_ukaz[fd][i] != '\n' && fd_ukaz[fd][i] != '\0')
		i++;
	*line = ft_strsub(fd_ukaz[fd], 0, i);
	if (fd_ukaz[fd][i] == '\n')
	{
		tmp = ft_strsub(fd_ukaz[fd], i + 1, ft_strlen(fd_ukaz[fd]) - i);
		ft_strdel(&fd_ukaz[fd]);
		fd_ukaz[fd] = tmp;
		if (fd_ukaz[fd][0] == '\0')
			ft_strdel(&fd_ukaz[fd]);
	}
	else if (fd_ukaz[fd][i] == '\0')
		ft_strdel(&fd_ukaz[fd]);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	char			*tmp;
	char			buf[BUFF_SIZE + 1];
	static char		*fd_ukaz[10240];

	if (fd < 0 || fd > 10240 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(fd_ukaz[fd]))
			fd_ukaz[fd] = ft_strnew(1);
		tmp = ft_strjoin(fd_ukaz[fd], buf);
		ft_strdel(&fd_ukaz[fd]);
		fd_ukaz[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (fd_ukaz[fd] == NULL)
		return (0);
	return (ft_write_in_line(fd_ukaz, line, fd));
}

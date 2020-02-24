/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 18:12:32 by aenstein          #+#    #+#             */
/*   Updated: 2020/02/24 19:42:12 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_wdcounter(char const *str, char c)
{
	int i;
	int words;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

int		get_width(char *file_name)
{
	int		fd;
	int		width;
	char	*line;

	width = 0;
	if ((fd = open(file_name, O_RDONLY, 0)) <= 0)
		error_write(ERR_MAP_READ);
	if ((get_next_line(fd, &line)) <= 0)
		error_write(ERR_MAP_READ);
	width = ft_wdcounter(line, ' ');
	free(line);
	close(fd);
	if (width == 0)
		error_write(ERR_MAP_READ);
	return (width);
}

int		get_height(char *file_name)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

void	matrix(int *z_coord, char *line, t_fdf *data)
{
	char	**nums;
	int		i;

	if (!(nums = ft_strsplit(line, ' ')))
		error_write(ERR_MAP_READ);
	i = 0;
	check_nums(nums, data);
	while (nums[i])
	{
		z_coord[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	data->width = get_width(file_name);
	check_file(file_name, data);
	data->height = get_height(file_name);
	i = 0;
	if (!(data->z_coord = (int**)malloc(sizeof(int*) * (data->height + 1))))
		error_write(ERR_MAP_READ);
	while (i < data->height)
		if (!(data->z_coord[i++] = (int*)malloc(sizeof(int) *
										(data->width + 1))))
			error_write(ERR_MAP_READ);
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		matrix(data->z_coord[i], line, data);
		free(line);
		i++;
	}
	data->z_coord[i] = NULL;
	close(fd);
}

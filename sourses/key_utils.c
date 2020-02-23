/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaland <bshaland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:02:12 by aenstein          #+#    #+#             */
/*   Updated: 2020/02/23 16:28:54 by bshaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	shif(int key, t_fdf *data)
{
	if (key == 0)
		data->shift_x -= 10;
	if (key == 2)
		data->shift_x += 10;
	if (key == 13)
		data->shift_y -= 10;
	if (key == 1)
		data->shift_y += 10;
}

void	zoom(int key, t_fdf *data)
{
	if (key == 69 || key == 5)
		data->zoom += 1;
	if ((key == 78 || key == 4) && data->zoom - 1 != 0)
		data->zoom -= 1;
}

void	rotate(int key, t_fdf *data)
{
	//data->rotation->projection = 3;
	if (key == 84)
		data->rotation->x_rot += 0.05;
	else if (key == 91)
		data->rotation->x_rot-= 0.05;
	else if (key == 86)
		data->rotation->y_rot -= 0.05;
	else if (key == 88)
		data->rotation->y_rot += 0.05;
	else if (key == 83 || key == 85)
		data->rotation->z_rot += 0.05;
	else if (key == 89 || key == 92)
		data->rotation->z_rot -= 0.05;
	else if (key == 25)
		data->rotation->projection = 1;
	else if (key == 29)
		data->rotation->projection = 2;
}

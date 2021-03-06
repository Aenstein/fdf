/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 17:09:13 by aenstein          #+#    #+#             */
/*   Updated: 2020/02/24 19:24:34 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <stdio.h>

# define HEIGHT			1400
# define WIDTH			2560
# define MENU_WIDTH		350
# define TEXT			0xFAEBD7
# define MENU_BACK		0x090909
# define BACK			0x0f0f0f
# define ORANGERED		0xFF4500
# define DARKORANGE		0xFF8C00
# define ORANGE			0xFFA500
# define GOLD			0xFFD700
# define YELLOW			0xFFFF00
# define MOVE			"Move: WASD or mouse left button"
# define BELOW			"Height of projection: below Q"
# define HEIGHTER		"Height of projection: highter E"
# define ERR_USAAGE     "Usege: ./fdf map_file."
# define ERR_MAP        "Incorrect map_file."
# define ERR_MAP_READ   "Reading error."

typedef enum
{
	false,
	true
}	t_bool;

typedef struct	s_step
{
	float	x_step;
	float	y_step;
}				t_step;

typedef struct	s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}				t_point;

typedef struct	s_rot
{
	double	x_rot;
	double	y_rot;
	double	z_rot;
	int		projection;
	int		z_projection;
}				t_rot;

typedef struct	s_mouse
{
	char	is_pressed;
	int		x;
	int		y;
	int		previous_x;
	int		previous_y;
}				t_mouse;

typedef struct	s_fdf
{
	int		width;
	int		height;
	int		zoom;
	int		color;
	int		**z_coord;
	int		max_z;
	int		min_z;
	int		shift_x;
	int		shift_y;
	int		color_num;
	char	*data_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	t_mouse	*mouse;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	t_rot	*rotation;
}				t_fdf;

void			read_file(char *file_name, t_fdf *data);
void			matrix(int *z_coord, char *line, t_fdf *data);
int				get_height(char *file_name);
int				get_width(char *file_name);
int				ft_wdcounter(char const *str, char c);
void			connect(t_point start, t_point end, t_fdf *data);
void			draw_map(t_fdf *data);
void			iso(float *x, float *y, float z, t_fdf *data);
void			parallel(float *x, float *y, float z, t_fdf *data);
float			maxf(float a, float b);
float			mod(float a);
float			min(float a, float b);
void			init(t_fdf *data, t_mouse *mouse, t_rot *rotation);
void			shif(int key, t_fdf *data);
void			zoom(int key, t_fdf *data);
void			fdf_init(t_fdf *data);
int				color(t_fdf *data, float z, float z1);
t_point			create_point(float x, float y, t_fdf *data);
void			error_write(char *s);
void			zoomstart(float *x, float *y, t_fdf *data);
void			shiftstart(float *x, float *y, float shift);
void			steps(float *x_step, float *y_step, t_point start, t_point end);
void			print_menu(t_fdf *data);
void			check_file(char *file_name, t_fdf *data);
void			pixel_put(t_fdf *data, int x, int y, int color);
void			draw_background(t_fdf *data);
int				ft_isdigit_base(char c, int base);
t_bool			ft_has_prefix(const char *str, int base);
t_bool			ft_isnumber(char *str, int base);
int				ft_atoi_base(const char *str, int base);
int				ft_isspace(int c);
int				get_color(t_point cur, t_point start, t_point end, t_step step);
int				get_light(int start, int end, float percentage);
int				get_default_color(int z, t_fdf *data);
float			percent(int start, int end, int current);
void			z_heigt(t_fdf *data);
void			rotate_x(float *y, float *z, double alpha);
void			rotate_y(float *x, float *z, double beta);
void			rotate_z(float *x, float *y, double gamma);
t_point			project(t_point p, t_fdf *fdf);
void			rotate(int key, t_fdf *data);
void			check_nums(char **nums, t_fdf *data);

#endif

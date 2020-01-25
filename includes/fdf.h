/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 11:07:30 by bedavis           #+#    #+#             */
/*   Updated: 2020/01/22 18:24:27 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx.h"
# include "libft.h"
# include "key_map.h"


# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define TEXT_COLOR 0xF3AF3D
# define TEXT_COLOR2 0xEAEAEA

typedef struct  s_point
{
	int			x;
	int			y;
	int			z;
	int			color;	
}				t_point;

typedef struct  s_map
{
	int			width;
	int			height;
	int			**z_matrix;
	//change!
	int			shift_x;
	int			shift_y;
	int 		zoom;
	int			color;
	int			flat;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_map;

typedef struct  s_line
{
	t_point		start;
	t_point		end;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
} 				t_line;

typedef struct	s_img
{
		void	*img_ptr;
		int		*data;
		int		size_l;
		int		bpp;
		int		endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_img		*img;
	t_map		*map;
}				t_mlx;



int				key_press(int key, t_map *map);
void			fdf_exit(char *reason);
void			read_file(char *file_name, t_map *map);
int				ft_wdcounter(char const *str, char c);
void 			draw_line(double x, double y, double x1, double y1, t_map *map);
void			draw(t_map *map);
void			print_usage(t_map *map);
int				mouse_press(int button, t_map *map);

#endif

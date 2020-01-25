/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <bedavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:52:00 by bedavis           #+#    #+#             */
/*   Updated: 2020/01/22 18:13:12 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double  max(double a, double b)
{
	return (a > b ? a : b);
}

static double my_abs(double a)
{
	return (a < 0 ? -a : a);
}

void	isomet(double *x, double *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
	return;
}

void 	draw_line(double x, double y, double x1, double y1, t_map *map)
{
	double step_x;
	double step_y;
	double max1;
	int z;
	int z1;

	z = map->flat * map->z_matrix[(int)y][(int)x];
	z1 = map->flat * map->z_matrix[(int)y1][(int)x1];
	//зуууум----------------
	x *= map->zoom;
	x1 *= map->zoom;
	y *= map->zoom;
	y1 *= map->zoom;
	//цвет--------------
	map->color = (z || z1) ? 0xC0C0C0 : 0x0000FF;
	//map->color = (z || z1) ? 0x008000 * z * 10 : 0x000080;
	//3d--------------------
	isomet(&x, &y, z);
	isomet(&x1, &y1, z1);
	//shift----------
	x += map->shift_x;
	y += map->shift_y;
	x1 += map->shift_x;
	y1 += map->shift_y;

	step_x = x1 - x;
	step_y = y1 - y;
	max1 =  max(my_abs(step_x), my_abs(step_y));
	step_x = step_x / max1;
	step_y = step_y / max1;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, (int)x, (int)y, map->color);
		x += step_x;
		y += step_y;
	}

}

void	draw(t_map *map)
{
	int x;
	int y;

	print_usage(map);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x < map->width - 1)
				draw_line(x, y, x + 1, y, map);
			if (y < map->height - 1)
				draw_line(x, y, x, y + 1, map);
			x++;
		}
		y++;
	}
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 11:18:22 by bedavis           #+#    #+#             */
/*   Updated: 2020/01/22 18:09:50 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key_map.h"
#include <stdlib.h>


int			key_press(int key, t_map *map)
{
	// t_fdf	*fdf;

	// fdf = (t_fdf *)param;
	if (key == MAIN_PAD_ESC)
		fdf_exit("Normal exit.");
	if (key == NUM_PAD_PLUS || key == MAIN_PAD_PLUS || key == MOUSE_SCROLL_UP)
		map->zoom += 5;
	if (key == NUM_PAD_MINUS || key == MAIN_PAD_MINUS || key == MOUSE_SCROLL_DOWN)
		map->zoom -= 5;
	if (key == ARROW_LEFT)
		map->shift_x -= 10;
	if 	(key == ARROW_RIGHT)
		map->shift_x += 10;
	if (key == ARROW_UP)
		map->shift_y -= 10;
	if (key == ARROW_DOWN)
		map->shift_y += 10;
	if (key == MAIN_PAD_LESS)
		map->flat -= 1;
	if (key == MAIN_PAD_MORE)
		map->flat += 1;
	/*	move(key, fdf);
	else if (key == NUM_PAD_1 || key == MAIN_PAD_1
		|| key == NUM_PAD_2 || key == MAIN_PAD_2
		|| key == NUM_PAD_3 || key == MAIN_PAD_3
		|| key == NUM_PAD_4 || key == MAIN_PAD_4
		|| key == NUM_PAD_6 || key == MAIN_PAD_6
		|| key == NUM_PAD_7 || key == MAIN_PAD_7
		|| key == NUM_PAD_8 || key == MAIN_PAD_8
		|| key == NUM_PAD_9 || key == MAIN_PAD_9)
		rotate(key, fdf);
	else if (key == MAIN_PAD_LESS || key == MAIN_PAD_MORE)
		flatten(key, fdf);
	else if (key == MAIN_PAD_P || key == MAIN_PAD_I)
		change_projection(key, fdf);*/

	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	draw(map);
	return (0);
}
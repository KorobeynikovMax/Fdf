/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 11:18:22 by bedavis           #+#    #+#             */
/*   Updated: 2019/12/25 11:19:05 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"
#include "key_map.h"
#include <stdlib.h>


int			key_press(int key, void *param)
{
	// t_fdf	*fdf;

	// fdf = (t_fdf *)param;
	param = (void*) param;
	if (key == MAIN_PAD_ESC)
		exit(0);
	/*if (key == NUM_PAD_PLUS || key == MAIN_PAD_PLUS
		|| key == NUM_PAD_MINUS || key == MAIN_PAD_MINUS)
		zoom(key, fdf);
	else if (key == ARROW_LEFT || key == ARROW_RIGHT
		|| key == ARROW_UP || key == ARROW_DOWN)
		move(key, fdf);
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
	return (0);
}
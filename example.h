/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 11:07:30 by bedavis           #+#    #+#             */
/*   Updated: 2019/12/23 11:12:58 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXAMPLE_H
# define EXAMPLE_H

# include <math.h>
# include "./minilibx/mlx.h"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

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
	t_img		img;
}				t_mlx;

int				key_press(int key, void *param);

#endif

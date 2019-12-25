/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 11:14:57 by bedavis           #+#    #+#             */
/*   Updated: 2019/12/25 10:39:32 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"
#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);			
}

int			deal_key(int key, void *param)
{
	param = 0;
	ft_putchar((char) key);
	return (0);
}

int			main(void)
{
	t_mlx	mlx;
	int		count_w;
	int		count_h;

	count_h = -1;
	count_w = -1;
	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "A Simple Text");
	mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);

	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_l, &mlx.img.endian);
	while (++count_h < WIN_HEIGHT)
	{
		count_w = -1;
		while (++count_w < WIN_WIDTH)
		{
			if (count_h == 200 || count_h == 400)
				mlx.img.data[count_h * WIN_WIDTH + count_w] = 0xFFF000;
			else
			if (count_w % 2)
				mlx.img.data[count_h * WIN_WIDTH + count_w] = 0xFFFFFF;
			else
				mlx.img.data[count_h * WIN_WIDTH + count_w] = 0;
		}
	}

	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0);
	mlx_key_hook(mlx.win, key_press, (void *)0);
	mlx_loop(mlx.mlx_ptr);

	return (0);
}

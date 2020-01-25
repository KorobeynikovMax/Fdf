/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 11:14:57 by bedavis           #+#    #+#             */
/*   Updated: 2020/01/25 12:49:57 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int			deal_key(int key, void *param)
{
	param = 0;
	ft_putchar((char) key);
	return (0);
}

int			main(int argc, char **argv)
{
	int		i;
	int		j;
	t_map *map = NULL;
	map = (t_map*)malloc(sizeof(map) + 100); //change!!!! no 100

	if (argc != 2)
		fdf_exit("error: wrong arguments count.");
	read_file(argv[1], map);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			printf("%4d", map->z_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}

	map->zoom = 5;
	map->flat = 1;
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			"bedavis");
	map->shift_x = 280;
	map->shift_y = 150;
	draw(map);
	mlx_key_hook(map->win_ptr, key_press, map);
	mlx_hook(map.win_ptr, 4, 0, mouse_press, (void *)&map);
	mlx_hook(map.win_ptr, 5, 0, mouse_release, (void *)&map);
	mlx_hook(map.win_ptr, 6, 0, mouse_move, (void *)&map);
	mlx_loop(map->mlx_ptr);
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	free(map);

/*----	fdf_exit("error: fail reading file.");----------------------------------------------
	count_h = -1;
	count_w = -1;
	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "bedavis' Fdf");
	mlx.img->img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);

	mlx.img->data = (int *)mlx_get_data_addr(mlx.img->img_ptr, &mlx.img->bpp, &mlx.img->size_l, &mlx.img->endian);

	t_point a;
	t_point b;
	a.x = 100;
	a.y = 300;
	a.color = 0x0000FF;
	b.x = 600;
	b.y = 800;
	b.color = 0x0000FF;
	double k = (b.y - a.y)/(b.x - a.x);
    double bb = (b.x*a.y - a.x*b.y)/(b.x - a.x);
	while (++count_h < WIN_HEIGHT)
	{
		count_w = -1;
		while (++count_w < WIN_WIDTH)
		{
			if ( count_h == (count_w * k + bb))
				mlx.img->data[count_h * WIN_WIDTH + count_w] = 0xFF00FF;
			else
				mlx.img->data[count_h * WIN_WIDTH + count_w] = 0xC0C0C0;
		}
	}
	
	//char *line;
	
	//int result;
	//result = ft_get_next_line(fd, &line);
	//printf("%s\n", line);
	close(fd);
	int f; 
	f = ft_isdigit(4);
	-------------------------------------------------------------*/
	


	//mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img->img_ptr, 0, 0);
	//mlx_key_hook(mlx.win, key_press, (void *)0);
	//mlx_loop(mlx.mlx_ptr);
	
	/*
	void *mlx_ptr;
	void *win_ptr;
	char *s = "PRIVET";
	t_point a;
	t_point b;
	a.x = 10;
	a.y = 20;
	a.color = 0x0000FF;
	b.x = 60;
	b.y = 10;
	b.color = 0x0000FF;
	int		count_w;
	int		count_h;
	count_h = -1;
	count_w = -1;
	void *img_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 300, 200, "ulaalaalaaa");
	mlx_pixel_put(mlx_ptr, win_ptr, 5, 5, 0xFF0000);
	mlx_string_put(mlx_ptr, win_ptr, 10, 10, 0x008000, s);



	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
	mlx_clear_window(mlx_ptr, win_ptr);
	mlx_destroy_window(mlx_ptr, win_ptr);
	*/
	return (0);
}

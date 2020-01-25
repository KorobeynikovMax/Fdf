/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:02:34 by bedavis           #+#    #+#             */
/*   Updated: 2020/01/17 14:40:22 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_height(char *file_name)
{
	int height;
	char *line;
	int fd;

	line = NULL;
	height = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		fdf_exit("error: invalid file.");
	while (ft_get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int		get_width(char *file_name)
{
	int width;
	char *line;
	int fd;

	line = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		fdf_exit("error: invalid file.");
	ft_get_next_line(fd, &line);
	width = ft_wdcounter(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	fill_matrix(int *z_line, char *line)
{
	char **nums;
	int i;

	nums = ft_strsplit(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *file_name, t_map *map)
{
	int fd;
	char *line;
	int i;

	map->height = get_height(file_name);
	map->width = get_width(file_name);
	map->z_matrix = (int **)malloc(sizeof(int*) * (map->height +1));
	i = 0;
	while (i <= map->height)
		map->z_matrix[i++] = (int *)malloc(sizeof(int) * (map->width + 1));
	if (!(fd = open(file_name, O_RDONLY)))
		fdf_exit("error: invalid file."); 
	i = 0;
	line = NULL;
	while (ft_get_next_line(fd, &line))
	{
		fill_matrix(map->z_matrix[i], line);
		free(line);
		i++;
	}
	close(fd);
	map->z_matrix[i] = NULL;
}
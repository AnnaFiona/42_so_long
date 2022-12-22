/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ip <ip@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:59:53 by aplank            #+#    #+#             */
/*   Updated: 2022/12/22 19:54:31 by ip               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int	get_map(t_data *data)
{
	int		fd;
	int		check;

	data->clover_count = 0;
	data->move_count = 0;
	data->p_x = 0;
	data->p_y = 0;
	data->e_x = 0;
	data->e_y = 0;


	data->buf = malloc(2000 * sizeof(char));
	fd = open(data->map_name, O_RDONLY);
	if (fd < 0)
		return (1);
	check = read(fd, data->buf, 2000);
	if (check <= 0 || check == 2000)
	{
		if (check == 2000)
			ft_printf("\n    ERROR: The map is too big\n\n");
		free(data->buf);
		return (1);
	}
	data->buf[check] = '\0';
	data->buf[check + 1] = '\0';
	data->map = ft_split(data->buf, '\n');
	close(fd);
	
	data->win_y = 0;
	data->win_x = ft_strlen(data->map[0]);
	while (data->map[data->win_y])
		data->win_y++;

	get_positions(data);
	if (data->p_x <= data->e_x)
		data->bat_look = 0;
	else
		data->bat_look = 1;
	return (0);
}

void	get_positions(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == 'P')
			{
				data->p_x = x;
				data->p_y = y;
			}
			if (data->map[y][x] == 'E')
			{
				data->e_x = x;
				data->e_y = y;
			}
			if (data->map[y][x] == 'C')
				data->clover_count++;
			x++;
		}
		y++;
	}
}

int	put_map(t_data *data)
{
	char	*str_move_cnt;
	
	if (data->win_ptr == NULL)
		return (0);
	str_move_cnt = ft_itoa(data->move_count);
	data->y = 0;
	while (data->map[data->y])
	{
		data->x = 0;
		while (data->map[data->y][data->x])
		{
			put_image(data);
			mlx_string_put(data->mlx_ptr, data->win_ptr, data->win_x * 20, 22, 0xe8faf7, str_move_cnt);
			data->x++;
		}
		data->y++;
	}
	free(str_move_cnt);
	return (0);
}

int	free_map(t_data *data)
{
	int	y;

	y = 0;
	while (data->map[y])
	{
		free(data->map[y]);
		y++;
	}
	free(data->map);
	free(data->buf);
	return (0);
}

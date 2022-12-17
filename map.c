/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplank <aplank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:59:53 by aplank            #+#    #+#             */
/*   Updated: 2022/12/17 16:38:59 by aplank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int	get_map(t_map *plan, char *map_name)
{
	int		fd;
	int		check;
	char	buf[1000];

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (1);
	check = read(fd, buf, 1000);
	if (check <= 0 || check == 1000)
		return (1);
	plan->map = ft_split(buf, '\n');
	plan->y = 0;
	plan->x = ft_strlen(plan->map[0]);
	while (plan->map[plan->y])
		plan->y++;
	get_p_position(plan);
	return (0);
}

int	get_p_position(t_map *plan)
{
	plan->p_y = 0;
	while (plan->map[plan->p_y])
	{
		plan->p_x = 0;
		while (plan->map[plan->p_y][plan->p_x] != '\0')
		{
			if (plan->map[plan->p_y][plan->p_x] == 'P')
			{
				printf("get_p_position p_x: %d		p_y: %d\n", plan->p_x, plan->p_y);
				return (0);
			}
			plan->p_x++;
		}
		plan->p_y++;
	}
	return (1);
}

int	put_map(t_data *window, t_textures *image, t_map *plan)
{
	plan->y = 0;
	while (plan->map[plan->y])
	{
		plan->x = 0;
		while (plan->map[plan->y][plan->x])
		{
			put_image(window, image, plan);
			plan->x++;
		}
		plan->y++;
	}
	return (0);
}

int	free_map(t_map *plan)
{
	int	y;

	y = 0;
	while (plan->map[y])
	{
		free(plan->map[y]);
		y++;
	}
	free(plan->map);
	return (0);
}

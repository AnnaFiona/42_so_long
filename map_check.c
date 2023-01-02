/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplank <aplank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:06:13 by aplank            #+#    #+#             */
/*   Updated: 2023/01/02 20:28:20 by aplank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_data *data, t_check *check)
{
	int	cnt;
	int	x;
	int	y;

	cnt = 1;
	check->exit_reach = 1;
	check->map[data->p_y][data->p_x] = 'x';
	while (cnt != 0)
	{
		y = 1;
		cnt = 0;
		while (check->map[y + 1])
		{
			x = 1;
			while (check->map[y][x + 1] != '\0')
			{
				cnt += field_check(check, x, y);
				x++;
			}
			y++;
		}
	}
}

int	field_check(t_check *check, int x, int y)
{
	int	cnt;

	cnt = 0;
	if (check->map[y - 1][x] == 'x' || check->map[y][x + 1] == 'x'
		|| check->map[y + 1][x] == 'x' || check->map[y][x - 1] == 'x')
	{
		if (check->map[y][x] == '1' || check->map[y][x] == 'x')
			return (0);
		else if (check->map[y][x] == 'C')
			check->clover_cnt--;
		else if (check->map[y][x] == 'E')
			check->exit_reach = 0;
		check->map[y][x] = 'x';
		cnt++;
	}
	return (cnt);
}

int	check_size_and_characters(t_check *check)
{
	size_t	width;
	int		y;

	y = 1;
	width = ft_strlen(check->map[0]);
	while (check->map[y])
	{
		if (ft_strlen(check->map[y]) != width)
		{
			ft_printf("\n    ERROR: The map is not rectangular\n\n");
			return (1);
		}
		if (check_characters(check, y))
			return (1);
		y++;
	}
	return (0);
}

int	check_characters(t_check *check, int y)
{
	int	x;

	x = 0;
	while (check->map[y][x])
	{
		if (!(check->map[y][x] == '0'
			|| check->map[y][x] == '1'
			|| check->map[y][x] == 'C'
			|| check->map[y][x] == 'P'
			|| check->map[y][x] == 'E'))
		{
			ft_printf("\n    ERROR: There is a %c in your map\n\n",
				check->map[y][x]);
			return (1);
		}
		x++;
	}
	return (0);
}

int	check_border(t_data *data, t_check *check)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (check->map[0][x])
		if (check->map[0][x++] != '1')
			return (1);
	x--;
	while (y < data->win_y)
		if (check->map[y++][x] != '1')
			return (1);
	y--;
	x = 0;
	while (check->map[y][x])
		if (check->map[y][x++] != '1')
			return (1);
	y = 0;
	while (y < data->win_y)
		if (check->map[y++][0] != '1')
			return (1);
	return (0);
}

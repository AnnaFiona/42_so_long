/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplank <aplank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:29:30 by aplank            #+#    #+#             */
/*   Updated: 2023/01/01 17:53:15 by aplank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check(t_data *data)
{
	t_check	check;

	check.map = ft_split(data->buf, '\n');
	check.clover_cnt = data->clover_count;
	if (check_size(&check) != 0)
	{
		ft_printf("\n    ERROR: The map is not rectangular\n\n");
		free_check(&check);
		return (1);
	}
	if (check_border(data, &check) != 0)
	{
		ft_printf("\n    ERROR: The border is not ok\n\n");
		free_check(&check);
		return (1);
	}
	check_count(&check);
	check_map(data, &check);
	if (put_error(data, &check) != 0)
	{
		free_check(&check);
		return (1);
	}
	free_check(&check);
	return (0);
}

void	check_count(t_check *check)
{
	int	x;
	int	y;

	y = 0;
	check->exit_cnt = 0;
	check->player_cnt = 0;
	while (check->map[y])
	{
		x = 0;
		while (check->map[y][x] != '\0')
		{
			if (check->map[y][x] == 'P')
				check->player_cnt++;
			if (check->map[y][x] == 'E')
				check->exit_cnt++;
			x++;
		}
		y++;
	}
}

int	put_error(t_data *data, t_check *check)
{
	if (check->player_cnt != 1)
		ft_printf("\n    ERROR: There are %d players\n\n", check->player_cnt);
	else if (check->exit_cnt != 1)
		ft_printf("\n    ERROR: There are %d exits\n\n", check->exit_cnt);
	else if (check->clover_cnt != 0)
		ft_printf("\n    ERROR: %d collectables can't be reached\n\n",
			check->clover_cnt);
	else if (check->exit_reach == 1)
		ft_printf("\n    ERROR: The exit can't be reached\n\n");
	else if (data->clover_count < 1)
		ft_printf("\n    ERROR: There needs to be at least one collectable\n\n");
	else
		return (0);
	return (1);
}

void	free_check(t_check *check)
{
	int	y;

	y = 0;
	while (check->map[y])
	{
		free(check->map[y]);
		y++;
	}
	free(check->map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplank <aplank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:50:11 by aplank            #+#    #+#             */
/*   Updated: 2023/01/02 20:20:11 by aplank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checking_input(t_data *data, int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("\n    ERROR: There are %d arguments. \
		There should be 2\n\n", argc);
		return (1);
	}
	data->map_name = argv[1];
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (checking_input(&data, argc, argv) == 1)
		return (0);
	if (get_map(&data))
		return (0);
	if (make_window(&data) == 1)
	{
		free_map(&data);
		return (0);
	}
	get_textures(&data);
	mlx_loop_hook(data.mlx_ptr, &put_map, &data);
	mlx_hook(data.win_ptr, 17, 0, &x_window, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &key_input, &data);
	mlx_loop(data.mlx_ptr);
	destroy_textures(&data);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	free_map(&data);
	return (0);
}

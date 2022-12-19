/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplank <aplank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:50:11 by aplank            #+#    #+#             */
/*   Updated: 2022/12/19 15:11:44 by aplank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main()
{
	t_data	data;	

	get_map(&data, "test_map");
	if (make_window(&data) == 1)
	{
		free_map(&data);
		return (1);
	}
	get_textures(&data);
	//put_map(&data);
	mlx_loop_hook(data.mlx_ptr, &put_map, &data);
	mlx_hook(data.win_ptr, 17, 0, &x_window, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &key_input, &data);
	//mlx_key_hook(data.win_ptr, &get_movement, &data);
	mlx_loop(data.mlx_ptr);
	destroy_textures(&data);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	free_map(&data);
	return (0);
}
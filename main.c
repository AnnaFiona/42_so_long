/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplank <aplank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:50:11 by aplank            #+#    #+#             */
/*   Updated: 2022/12/17 16:18:26 by aplank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main()
{
	t_data		window;
	t_textures	image;
	t_map		plan;

	get_map(&plan, "test_map");
	printf("main p_x: %d		p_y: %d\n", plan.p_x, plan.p_y);
	if (make_window(&window, &plan) == 1)
		return (1);	
	get_textures(&window, &image);
	put_map(&window, &image,&plan);
	mlx_loop_hook(window.mlx_ptr, &handle_no_event, &window);
	mlx_hook(window.win_ptr, 17, 0, &x_window, &window);
	mlx_key_hook(window.win_ptr, &key_input, &window);
	//mlx_key_hook(window.win_ptr, &get_movement, &window);
	mlx_loop(window.mlx_ptr);
	destroy_textures(&window, &image);
	mlx_destroy_display(window.mlx_ptr);
	free(window.mlx_ptr);
	free_map(&plan);
	return (0);
}
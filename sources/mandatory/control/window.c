/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:26:11 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/12 19:25:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	*window(void)
{
	return (c()->window);
}

void	initialize_window(void)
{
	t_camera	*cam;
	void		*window;

	cam = &c()->camera;
	window = mlx_new_window(c()->mlx, cam->width, cam->height, "miniRT");
	c()->window = window;
	if (c()->window == NULL)
		die(MLX_NEW_WINDOW_ERR);
}

void	destroy_window(void)
{
	mlx_destroy_window(c()->mlx, c()->window);
	c()->window = NULL;
}

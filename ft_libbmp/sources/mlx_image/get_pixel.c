/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 10:57:48 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/29 15:59:41 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

int	mlx_image_get_pixel_int(t_mlx_image *image, int x, int y)
{
	int	*pixel_color;

	if (mlx_out_of_bounds(image, x, y))
		return (RED);
	pixel_color = (int *)&image->data[mlx_get_index(image, x, y)];
	return (*pixel_color);
}

t_rgb	mlx_image_get_pixel_rgb(t_mlx_image *image, int x, int y)
{
	return (int_to_rgb(mlx_image_get_pixel_int(image, x, y)));
}

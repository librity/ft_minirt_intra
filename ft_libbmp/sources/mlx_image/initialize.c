/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 23:32:27 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:04:20 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

void	mlx_image_initialize(t_mlx_image *image, void *mlx,
			int width, int height)
{
	image->mlx = mlx;
	image->img = mlx_new_image(mlx, width, height);
	die_if_null(image->img, EC_MLX_IMAGE_INIT);
	image->data = mlx_get_data_addr(image->img,
			&image->bits_per_pixel,
			&image->line_length,
			&image->endian);
	die_if_null(image->data, EC_MLX_IMAGE_INIT);
	image->width = width;
	image->height = height;
	image->half_width = width / 2.0;
	image->half_height = height / 2.0;
}

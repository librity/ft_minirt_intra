/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:43:41 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 23:14:52 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

static void	transfer_pixels(t_mlx_image *image, t_bitmap *bm_image)
{
	int		x;
	int		y;
	int		color_int;
	t_rgb	colot_rgb;

	x = image->width;
	while (x--)
	{
		y = image->height;
		while (y--)
		{
			color_int = mlx_image_get_pixel_int(image, x, y);
			colot_rgb = int_to_rgb(color_int);
			bm_draw(bm_image, colot_rgb, x, image->height - 1 - y);
		}
	}
}

void	mlx_image_save_bm(t_mlx_image *image, char *filename)
{
	t_bitmap	*bitmap;

	bitmap = bm_initialize(image->width, image->height);
	transfer_pixels(image, bitmap);
	bm_save(bitmap, filename);
	bm_free(bitmap);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:22:42 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/29 15:58:55 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

static bool	bm_out_of_bounds(t_bitmap *bitmap, int x, int y)
{
	if (x < 0)
		return (true);
	if (x >= bitmap->header.width)
		return (true);
	if (y < 0)
		return (true);
	if (y >= bitmap->header.height)
		return (true);
	return (false);
}

static void	set_pixel(t_rgb *pxl,
					unsigned char red,
					unsigned char green,
					unsigned char blue)
{
	pxl->red = red;
	pxl->green = green;
	pxl->blue = blue;
}

void	bm_draw(t_bitmap *bitmap, t_rgb color, int x, int y)
{
	t_rgb	*target_pixel;

	if (bm_out_of_bounds(bitmap, x, y))
		return ;
	target_pixel = &(bitmap->pixels[y][x]);
	set_pixel(target_pixel, color.red, color.green, color.blue);
}

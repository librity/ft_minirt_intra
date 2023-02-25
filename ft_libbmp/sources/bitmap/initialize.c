/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 01:12:49 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 16:04:09 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

static void	allocate_pixels(t_bitmap *bitmap)
{
	size_t	height;
	size_t	current_row;
	size_t	row_size;

	height = abs(bitmap->header.height);
	bitmap->pixels = malloc(sizeof(t_rgb *) * height);
	die_if_null(bitmap->pixels, EC_BAD_MALLOC);
	row_size = sizeof(t_rgb) * bitmap->header.width;
	current_row = 0;
	while (current_row < height)
	{
		bitmap->pixels[current_row] = malloc(row_size);
		die_if_null(bitmap->pixels[current_row], EC_BAD_MALLOC);
		current_row++;
	}
}

static void	initialize_header(t_header *header,
								int width,
								int height)
{
	size_t	adjusted_width;
	size_t	positive_height;
	size_t	padding;

	padding = width % 4;
	adjusted_width = padding + sizeof(t_rgb) * width;
	positive_height = abs(height);
	header->buffer_size = adjusted_width * positive_height;
	header->buffer_reserved = 0;
	header->buffer_offset = 54;
	header->total_size = 40;
	header->width = width;
	header->height = height;
	header->planes = 1;
	header->bit_count = 24;
	header->compression = 0;
	header->image_size = 0;
	header->x_resolution_ppm = 0;
	header->y_resolution_ppm = 0;
	header->colors_used = 0;
	header->important_colors = 0;
}

void	*bm_initialize(int width, int height)
{
	t_bitmap	*bitmap;

	bitmap = malloc(sizeof(t_bitmap));
	die_if_null(bitmap, EC_BAD_MALLOC);
	initialize_header(&(bitmap->header), width, height);
	allocate_pixels(bitmap);
	return (bitmap);
}

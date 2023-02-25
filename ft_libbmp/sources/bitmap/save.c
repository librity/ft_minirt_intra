/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 01:10:04 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/20 18:54:49 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

static size_t	resolve_offset(t_bitmap *bitmap, t_writer *ctl)
{
	if (bitmap->header.height > 0)
		return (0);
	return (ctl->height - 1);
}

static void	initialize_ctl(t_bitmap *bitmap, t_writer *ctl)
{
	ctl->height = abs(bitmap->header.height);
	ctl->offset = resolve_offset(bitmap, ctl);
	ctl->row_width = sizeof(t_rgb) * bitmap->header.width;
	ctl->padding_width = sizeof(unsigned char) * (bitmap->header.width % 4);
	ctl->padding[0] = '\0';
	ctl->padding[1] = '\0';
	ctl->padding[2] = '\0';
}

static void	write_pixels(t_bitmap *bitmap, int fd)
{
	t_writer	ctl;
	size_t		row;
	int			row_index;
	t_rgb		*row_pixels;

	initialize_ctl(bitmap, &ctl);
	row = 0;
	while (row < ctl.height)
	{
		row_index = abs((int)(ctl.offset - row));
		row_pixels = bitmap->pixels[row_index];
		write(fd, row_pixels, ctl.row_width);
		write(fd, ctl.padding, ctl.padding_width);
		row++;
	}
}

static void	write_header(t_header *header,
							int fd)
{
	if (header == NULL)
	{
		close(fd);
		bm_die(EC_NO_HEADER);
	}
	write(fd, BITMAP_MAGIC_BITS, 2);
	write(fd, header, sizeof(*header));
}

void	bm_save(t_bitmap *bitmap, char *filename)
{
	int	fd;

	fd = open(filename, O_CREAT | O_RDWR, 0664);
	if (fd < 0)
		bm_die(EC_OPEN_BITMAP);
	write_header(&(bitmap->header), fd);
	write_pixels(bitmap, fd);
	close(fd);
}

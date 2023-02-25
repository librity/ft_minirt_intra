/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:23:35 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/29 15:59:41 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNALS_H
# define INTERNALS_H

# include <fcntl.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

/******************************************************************************\
 * COLORS
\******************************************************************************/

# define T_MASK 0xFF000000
# define R_MASK 0x00FF0000
# define G_MASK 0x0000FF00
# define B_MASK 0x000000FF

# define BLACK 0x00000000
# define WHITE 0x00FFFFFF
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF

typedef struct s_rgb
{
	unsigned char	blue;
	unsigned char	green;
	unsigned char	red;
}					t_rgb;

typedef struct s_trgb
{
	unsigned char	transparency;
	unsigned char	blue;
	unsigned char	green;
	unsigned char	red;
}					t_trgb;

int					int_get_t(int color);
int					int_get_r(int color);
int					int_get_g(int color);
int					int_get_b(int color);
int					int_zero_transparency(int color);

int					trgb_chars_to_int(unsigned char transparency,
						unsigned char red,
						unsigned char green,
						unsigned char blue);
int					trgb_to_int(t_trgb color);

t_rgb				color_rgb(unsigned char red, unsigned char green,
						unsigned char blue);
int					rgb_to_int(t_rgb color);
int					rgb_chars_to_int(unsigned char red, unsigned char green,
						unsigned char blue);

t_trgb				int_to_trgb(int color);
t_rgb				int_to_rgb(int color);

/******************************************************************************\
 * BITMAP
\******************************************************************************/

# define BITMAP_MAGIC_BITS "BM"

typedef struct s_header
{
	unsigned int	buffer_size;
	unsigned int	buffer_reserved;
	unsigned int	buffer_offset;

	unsigned int	total_size;
	int				width;
	int				height;

	unsigned short	planes;
	unsigned short	bit_count;
	unsigned int	compression;
	unsigned int	image_size;
	int				x_resolution_ppm;
	int				y_resolution_ppm;
	unsigned int	colors_used;
	unsigned int	important_colors;
}					t_header;

typedef struct s_bitmap
{
	t_header	header;
	t_rgb		**pixels;
}					t_bitmap;

typedef struct s_writer
{
	size_t			height;
	size_t			offset;
	size_t			row_width;
	size_t			padding_width;
	unsigned char	padding[3];
}					t_writer;

extern void			*bm_initialize(int width, int height);

extern void			bm_draw(t_bitmap *bitmap, t_rgb color, int x, int y);

extern void			bm_save(t_bitmap *bitmap, char *filename);

extern void			bm_free(t_bitmap *bitmap);

/******************************************************************************\
 * MLX
\******************************************************************************/

typedef struct s_mlx_image
{
	void			*mlx;
	void			*img;
	char			*data;

	int				width;
	int				height;
	int				half_width;
	int				half_height;

	int				line_length;
	int				bits_per_pixel;
	int				endian;
}					t_mlx_image;

void				mlx_image_initialize(t_mlx_image *image, void *mlx,
						int width, int height);

void				mlx_image_draw_int(t_mlx_image *image, int color,
						int x, int y);
void				mlx_image_draw_rgb(t_mlx_image *image, t_rgb color,
						int x, int y);

int					mlx_image_get_pixel_int(t_mlx_image *image, int x, int y);
t_rgb				mlx_image_get_pixel_rgb(t_mlx_image *image, int x, int y);

void				mlx_image_save_bm(t_mlx_image *image, char *filename);

void				mlx_image_destroy(t_mlx_image *image);

bool				mlx_out_of_bounds(t_mlx_image *image, int x, int y);
int					mlx_get_index(t_mlx_image *image, int x, int y);

/******************************************************************************\
 * UTILS
\******************************************************************************/

int					abs(int number);
void				putstr(char *s);

/******************************************************************************\
 * ERRORS
\******************************************************************************/

typedef enum e_errors
{
	EC_OPEN_BITMAP = 1,
	EC_NO_HEADER,
	EC_BAD_MALLOC,
	EC_MLX_IMAGE_INIT,
	EC_GENERIC
}					t_errors;
void				bm_die(t_errors code);
void				die_if_null(void *ptr, t_errors code);

#endif

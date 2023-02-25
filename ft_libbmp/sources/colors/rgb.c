/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:23:09 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 13:18:31 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

t_rgb	color_rgb(unsigned char red, unsigned char green, unsigned char blue)
{
	return ((t_rgb){blue, green, red});
}

int	rgb_chars_to_int(unsigned char red, unsigned char green, unsigned char blue)
{
	return (trgb_chars_to_int(0, red, green, blue));
}

int	rgb_to_int(t_rgb color)
{
	return (
		trgb_chars_to_int(
			0,
			color.red,
			color.green,
			color.blue));
}

t_rgb	int_to_rgb(int color)
{
	t_rgb	rgb;

	rgb.red = (unsigned char)(color >> 16);
	rgb.green = (unsigned char)(color >> 8);
	rgb.blue = (unsigned char)color;
	return (rgb);
}

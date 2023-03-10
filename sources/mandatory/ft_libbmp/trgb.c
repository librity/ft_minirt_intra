/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trgb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:44:29 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/25 18:18:15 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	trgb_chars_to_int(
	unsigned char transparency,
	unsigned char red,
	unsigned char green,
	unsigned char blue)
{
	return (transparency << 24 | red << 16 | green << 8 | blue);
}

int	trgb_to_int(t_trgb color)
{
	return (
		trgb_chars_to_int(
			color.transparency,
			color.red,
			color.green,
			color.blue));
}

t_trgb	int_to_trgb(int color)
{
	t_trgb	trgb;

	trgb.transparency = (unsigned char)(color >> 24);
	trgb.red = (unsigned char)(color >> 16);
	trgb.green = (unsigned char)(color >> 8);
	trgb.blue = (unsigned char)color;
	return (trgb);
}

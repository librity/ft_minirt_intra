/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_constants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:23:09 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/20 19:00:41 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

t_rgb	rgb_white(void)
{
	return (color_rgb(255, 255, 255));
}

t_rgb	rgb_black(void)
{
	return (color_rgb(0, 0, 0));
}

t_rgb	rgb_blue(void)
{
	return (color_rgb(0, 0, 255));
}

t_rgb	rgb_green(void)
{
	return (color_rgb(0, 255, 0));
}

t_rgb	rgb_red(void)
{
	return (color_rgb(255, 0, 0));
}

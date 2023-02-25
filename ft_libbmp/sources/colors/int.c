/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:44:29 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/03/21 13:18:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

int	int_get_t(int color)
{
	return (color & T_MASK);
}

int	int_get_r(int color)
{
	return (color & R_MASK);
}

int	int_get_g(int color)
{
	return (color & G_MASK);
}

int	int_get_b(int color)
{
	return (color & B_MASK);
}

int	int_zero_transparency(int color)
{
	int	transparency;

	transparency = color >> 24 << 24;
	color = color - transparency;
	return (color);
}

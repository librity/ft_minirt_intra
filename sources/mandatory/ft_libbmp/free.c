/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 01:15:39 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/25 18:18:15 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	bm_free(t_bitmap *bitmap)
{
	size_t	height;
	size_t	current_row;

	height = abs(bitmap->header.height);
	current_row = 0;
	while (current_row < height)
		free(bitmap->pixels[current_row++]);
	free(bitmap->pixels);
	free(bitmap);
}

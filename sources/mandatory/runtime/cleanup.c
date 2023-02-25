/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:15:13 by lpaulo-m          #+#    #+#             */
/*   Updated: 2023/02/06 11:55:06 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	cleanup(void)
{
	free_world_lalloc();
	mlx_clear_window(mlx(), window());
	destroy_camera();
	destroy_window();
	destroy_mlx();
}

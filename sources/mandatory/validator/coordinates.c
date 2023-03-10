/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:58:20 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/02/26 16:21:49 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	val_norm_coordinate(char *line);

int	check_norm_coordinate(char *line)
{
	if (check_coordinate(line) == false)
		return (false);
	if (val_norm_coordinate(line) == false)
		return (false);
	return (true);
}

static int	val_norm_coordinate(char *line)
{
	char	**cord;
	double	x;
	double	y;
	double	z;
	t_v3d	normal;

	cord = ft_split(line, ',');
	x = ft_atof(cord[0]);
	y = ft_atof(cord[1]);
	z = ft_atof(cord[2]);
	normal = vector(x, y, z);
	ft_free_strarr(cord);
	if (doubles_are_equal(magnitude(normal), 1.0))
		return (true);
	return (false);
}

int	check_coordinate(char *line)
{
	if (!*line)
		return (false);
	if (ft_isfloat(&line) == false)
		return (false);
	line++;
	if (ft_isfloat(&line) == false)
		return (false);
	line++;
	if (ft_isfloat(&line) == false)
		return (false);
	if (*line != ' ' && *line != '\t')
		return (false);
	return (true);
}

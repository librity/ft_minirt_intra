/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:01:02 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/12/29 16:01:03 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <internals.h>

static char	*g_error_messages[EC_GENERIC] = {
	"Couldn't create bitmap file.",
	"Can't save bitmap with unitialized header.",
	"Unable to allocate required memory.",
	"Couldn't initialize mlx image.",
	"Generic ft_libbmp error.",
};

static void	print_error(char *message)
{
	putstr("\033[0;31mERROR\n");
	putstr(message);
	putstr("\033[0m\n");
}

void	bm_die(t_errors code)
{
	print_error(g_error_messages[code]);
	exit(EXIT_FAILURE);
}

void	die_if_null(void *ptr, t_errors code)
{
	if (ptr == NULL)
		bm_die(code);
}

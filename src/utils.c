/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:13:26 by ohanchak          #+#    #+#             */
/*   Updated: 2023/12/11 17:49:20 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	key_space(t_fdf *fdf)
{
	if (fdf->map.isometric++ % 2)
		fdf->map.angle_z *= 0.2;
	else
		fdf->map.angle_z *= 5;
}

void	check_rows_col(int *cols, int *rows, int *len)
{
	if (*len > *cols)
		*cols = *len;
	if (*cols == *len)
		*rows += 1;
	else
		ft_message("Wrong value in map", 4);
}

int	ft_open(char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_message("Problem with open file", 1);
	return (fd);
}

int	close_window(t_fdf *fdf)
{
	fdf = NULL;
	exit(0);
}

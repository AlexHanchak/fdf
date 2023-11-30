/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:13:26 by ohanchak          #+#    #+#             */
/*   Updated: 2022/12/28 19:15:26 by ohanchak         ###   ########.fr       */
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

void	fdf_terminate(t_fdf *fdf)
{
	free(fdf);
	exit(0);
}

void	check_rows_col(int *cols, int *rows, int *len)
{
	if (*len > *cols)
		*cols = *len;
	if (*cols == *len)
		*rows += 1;
	else
		ft_message("problem with content in file", 4);
}

int	ft_open(char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_message("Check file something wrong", 1);
	return (fd);
}

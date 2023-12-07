/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:50:16 by ohanchak          #+#    #+#             */
/*   Updated: 2023/12/07 15:43:06 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	count_values(char *line)
{
	int		len;

	len = 0;
	while (*line)
	{
		if (ft_isdigit(*line))
		{
			len += 1;
			while (ft_isdigit(*line))
				line += 1;
		}
		else if (*line != ' ' && *line != '-')
			ft_message("read error or in file wrong value", 5);
		line += 1;
	}
	return (len);
}

static void	count_lines(t_fdf *fdf, char *map_file)
{
	int		fd;
	int		len;
	int		rows;
	int		cols;
	char	*line;

	rows = 0;
	cols = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_message("open file error", 1);
	while (get_next_line(fd, &line) == 1)
	{
		if (*line == '\0')
			break ;
		len = count_values(line);
		check_rows_col(&cols, &rows, &len);
		free(line);
	}
	if (close(fd) < 0)
		ft_message("problem with closing file", 2);
	fdf->map.width = cols;
	fdf->map.height = rows;
}

static void	get_values(t_fdf *fdf, int y, int z, char *line)
{
	int		i;
	char	**split;

	split = ft_split(line, ' ');
	if (split)
	{
		i = 0;
		while (split[i] && (y != fdf->map.width))
		{
			fdf->map.values[z][y] = ft_atoi(split[i++]);
			y += 1;
		}
		ft_free((void **) split);
	}
}

void	ft_read(char *map_file, t_fdf *fdf)
{
	int		y;
	int		z;
	int		fd;
	char	*line;

	y = 0;
	z = 0;
	count_lines(fdf, map_file);
	fd = ft_open(map_file);
	fdf->map.values = (int **)malloc(sizeof(int *) * fdf->map.height);
	if (!fdf->map.values)
		ft_message("cant allocate memory", 3);
	while (get_next_line(fd, &line) && z != fdf->map.height)
	{
		fdf->map.values[z] = (int *)malloc(sizeof(int) * fdf->map.width);
		if (!fdf->map.values[z])
			ft_message("check val then read", 3);
		get_values(fdf, y, z, line);
		y = 0;
		z++;
		free(line);
	}
	if (close(fd) < 0)
		ft_message("inf loop at close state", 2);
}

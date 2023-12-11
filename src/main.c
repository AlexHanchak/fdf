/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:51:22 by ohanchak          #+#    #+#             */
/*   Updated: 2023/12/11 18:17:29 by ohanchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	help_for_fdf(void)
{
	ft_putstr_fd("Usage:\n\t", 1);
	ft_putstr_fd("FDF ", 1);
	ft_putstr_fd(" need fdf_file\n", 1);
	ft_putstr_fd("Controls:\n", 1);
	ft_putstr_fd("\t[Esc]        -> Exit.\n", 1);
	ft_putstr_fd("\t[R]          -> Reset.\n", 1);
	ft_putstr_fd("\t[C]          -> Colorize!.\n", 1);
	ft_putstr_fd("\t[B][N]       -> Zoom.\n", 1);
	ft_putstr_fd("\t[J][K]       -> Rotation time!\n", 1);
	ft_putstr_fd("\t[Space]      -> Camera.\n", 1);
	ft_putstr_fd("\t[W][A][S][D] -> Move obj.\n", 1);
}

static void	reset_color_map(t_fdf *fdf)
{
	fdf->map.coordinate_z = 0;
	fdf->map.coordinate_y = 0;
	fdf->map.x_value = 1.00;
	fdf->map.angle_y = cos(M_PI / 3);
	fdf->map.angle_z = fdf->map.angle_y * sin(M_PI / 6);
	if (fdf->map.width > fdf->map.height)
		fdf->map.zoom = ceil((WIN_WIDTH / fdf->map.width) + MAGIC_ZOOM);
	else
		fdf->map.zoom = ceil((WIN_HEIGHT / fdf->map.height) + MAGIC_ZOOM);
	fdf->map.isometric = 1;
	fdf->color.red = 0x4F;
	fdf->color.green = 0x4F;
	fdf->color.blue = 0x4F;
}

static void	colors_rand(t_fdf *fdf)
{
	fdf->color.red = (rand() % 0x7F);
	fdf->color.green = (rand() % 0x7F);
	fdf->color.blue = (rand() % 0x7F);
}

static int	keys_manip(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESCAPE)
		close_window(fdf);
	else if (keycode == KEY_ANSI_R)
		reset_color_map(fdf);
	else if (keycode == KEY_ANSI_C)
		colors_rand(fdf);
	else if (keycode == KEY_ANSI_W)
		fdf->map.coordinate_z -= 1;
	else if (keycode == KEY_ANSI_S)
		fdf->map.coordinate_z += 1;
	else if (keycode == KEY_ANSI_D)
		fdf->map.coordinate_y += 1;
	else if (keycode == KEY_ANSI_A)
		fdf->map.coordinate_y -= 1;
	else if (keycode == KEY_ANSI_B)
		fdf->map.zoom += 1;
	else if ((keycode == KEY_ANSI_N) && (fdf->map.zoom > MAX_ZOOM))
		fdf->map.zoom -= 1;
	else if ((keycode == KEY_ANSI_J) && (fdf->map.x_value < MAX_X))
		fdf->map.x_value += 0.25;
	else if ((keycode == KEY_ANSI_K) && (fdf->map.x_value > -MAX_X))
		fdf->map.x_value -= 0.25;
	else if (keycode == KEY_SPACE)
		key_space(fdf);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc == 2)
	{
		ft_read(argv[1], &fdf);
		reset_color_map(&fdf);
		fdf.t_v.init = mlx_init();
		fdf.t_v.win = mlx_new_window(fdf.t_v.init, WIN_WIDTH,
				WIN_HEIGHT, "FDF");
		mlx_hook(fdf.t_v.win, 17, 0, close_window, &fdf);
		mlx_hook(fdf.t_v.win, 2, 3, keys_manip, &fdf);
		mlx_loop_hook(fdf.t_v.init, ft_draw, &fdf);
		mlx_loop(fdf.t_v.init);
	}
	else
		return (help_for_fdf(), 0);
	ft_free((void **) fdf.map.values);
	return (0);
}

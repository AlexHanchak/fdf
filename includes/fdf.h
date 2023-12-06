
#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "keys.h"

# define MAX_X			(10)
# define MAX_ZOOM		(5)
# define MAGIC_ZOOM		(2)
# define WIN_WIDTH		(1280)
# define WIN_HEIGHT		(720)

typedef struct mlx
{
	void*		window;
	void*		context;
	int32_t		width;
	int32_t		height;
	double		delta_time;
}	mlx_t;

typedef struct s_mlx
{
	void	*init;
	void	*win;
	void	*img;
}				t_mlx;

typedef struct s_image
{
	char	*data;
	int		size;
	int		endian;
	int		bpp;
}				t_image;

typedef struct s_map
{
	int		**values;
	int		width;
	int		height;
	int		coordinate_y;
	int		coordinate_z;
	int		y0;
	int		y1;
	int		z0;
	int		z1;
	int		zoom;
	int		isometric;
	double	x_value;
	double	angle_y;
	double	angle_z;
}				t_map;

typedef struct s_color
{
	int		red;
	int		green;
	int		blue;
}				t_color;

typedef struct s_fdf
{
	t_mlx	mlx;
	t_map	map;
	t_image	image;
	t_color	color;
}				t_fdf;

void			key_space(t_fdf *fdf);
void			fdf_terminate(t_fdf *fdf);
void			check_rows_col(int *cols, int *rows, int *len);
int				ft_open(char *map_file);

void			ft_read(char *map_file, t_fdf *fdf);
int				ft_draw(t_fdf *fdf);

#endif

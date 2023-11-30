
#ifndef FDF_H
# define FDF_H

/*
** Required header files.
*/

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>

/*
** User defined header files.
*/

# include "mlx.h"
# include "../libft/libft.h"
# include "keys.h"

/*
** Macros for the max value of x coordinate, the window size (width and height),
** and the title of the window (removing the .fdf extension).
*/

# define MAX_X			(10)
# define MAX_ZOOM		(5)
# define MAGIC_ZOOM		(2)
# define WIN_WIDTH		(1280)
# define WIN_HEIGHT		(720)

/*
** FDF Structures
**
** @t_mlx   : required minilibx arguments.
** @t_image : variables to be used for creation of the image (map).
**            data -> information about the image, allowing to be modified.
**            size -> move from one line to another in the image.
**            endian -> how the pixel color in the image needs to be stored.
**            bpp -> filled with the number of bits to represent a pixel color.
** @t_map   : values used to manipulate the fdf map.
** @t_color : define the color, rgb value (24-bits).
** @t_fdf   : nested structure that calls all of the other structures.
*/

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

/*
** Prototypes of the functions.
*/

void			key_space(t_fdf *fdf);
void			ft_exit(t_fdf *fdf);
void			ft_check(int *cols, int *rows, int *len);
int				ft_open(char *map_file);

void			ft_read(char *map_file, t_fdf *fdf);
int				ft_draw(t_fdf *fdf);

#endif

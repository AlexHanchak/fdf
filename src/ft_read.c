
#include "../includes/fdf.h"

/*
** Gets the number values in each line from the fdf file.
** If there's an invalid character in the line, prints an error message.
*/

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
			ft_error("Invalid characters or read error...!!!", 5);
		line += 1;
	}
	return (len);
}

/*
** Count and initializes the number of lines (rows) and columns (cols )that the file has.
** This value is used to allocate the correct memory size
** for the two dimensional array.
** If the total values from every line is not equal to the other lines,
** there is an error with the fdf file...
*/

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
		ft_error("Error opening file!!!", 1);
	while (get_next_line(fd, &line)==1)
	{
		if (*line == '\0')
			break ;
		len = count_values(line);
		ft_check(&cols, &rows, &len);
		free(line);
	}
	if (close(fd) < 0)
		ft_error("Error closing file!!!", 2);
	fdf->map.width = cols;
	fdf->map.height = rows;
}

/*
** Gets and store the values from the file into a two dimensional array,
** by atoi-ing every little value (converting from ascii to ints).
*/

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

/*
** Read the fdf file, allocates in memory the correct size of the height
** and width of the map.
*/

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
		ft_error("Memory Allocation failed!!!", 3);
	while (get_next_line(fd, &line) && z != fdf->map.height)
	{
		fdf->map.values[z] = (int *)malloc(sizeof(int) * fdf->map.width);
		if (!fdf->map.values[z])
			ft_error("Memory Allocation failed! :O", 3);
		get_values(fdf, y, z, line);
		y = 0;
		z++;
		free(line);
	}
	if (close(fd) < 0)
		ft_error("Error closing file! WTF?! :)", 2);
}

# 42 FdF
 
A simple 3D height-map renderer. You can rotate models, color is defined by
relative height in the map. More features planned!

## Features
* Simple file format definition (array of space-separated integers)
* 3D rotations with the mouse
* Camera controls (zoom, translate)
* Pretty color gradients!
* Double-buffered
* Line clipping

### Planned features
* Other projections (right now it's just orthographic)
* Different view modes: point map, wireframe, and filled
* More color modes: gradient, file-defined and z-buffer
* Depth shader
* Multithreaded calculations (OpenCL even?)
* Anti-aliased rendering
* Level-of-detail (less points when you zoom out on huge maps)

## Compiling and running
Run `make`. An executable will compile. Currently only tested on OS X.

Run it with `./fdf [map]`. A bunch of sample maps are provided in the `test_maps`
directory. One of the popular maps is `test_maps/42.fdf`.

Controls are: drag with left click to rotate, drag with right to zoom, drag with
both to move around.

## FDF Usage

```
Usage:		FDF		fdf_file

Controls:

	[Esc]        -> Exit the program.
	[R]          -> Reset the map.
	[M]          -> Colorize this shit!.
	[B][N]       -> Zoom in and zoom out.
	[J][K]       -> Spiky time!
	[Space]      -> Change the camera(isometric <-> plain).
	[W][A][S][D] -> Move the map.
```

## Additional information

If you are going to use this code for your 42 project make sure to delete all the comments 
and double check the norms. To understand the project better you can read the [FdF.pdf](FdF.pdf).
If you find any bugs write an issue.

# ifndef GRAPHICS_H_
# define GRAPHICS_H_

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <bsd/string.h>
# include "../minilibx/mlx.h"

# define WIDTH  1200
# define HEIGHT 600
# define ECHAP  53

typedef struct     s_gui
{
  char         **map;
  int          h;
  int          l;
  int          r;
  int          v;
  int          b;
  int          map_x;
  int          map_y;
  char         *ret;
  void         *ret2;
  void         *win;
  void         *mlx;
  void         *img;
  void         *img2;
  int          bits_per_pixel;
  int          size_line;
  int          endian;
  int          pause;
}              t_gui;

# endif // GRAPHICS_H_



#include "graphics.h"

static int     loop_key_hook(t_gui *p)
{
  char     *str;

  if (p->pause == 0)
  {
    p->ret = mlx_get_data_addr(p->img, &(p->bits_per_pixel), &(p->size_line), &(p->endian));
    //read_output(p);
    //draw(p);
    mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
    mlx_put_image_to_window(p->mlx, p->win, p->img2, 0, 0);
    mlx_destroy_image(p->mlx, p->img);
    p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
    //print_final(p);
  }
  if (p->pause == 1)
  {
    str = "PAUSE";
    mlx_string_put(p->mlx, p->win, (WIDTH / 4) - 10, (HEIGHT / 2) - 10, 0x0FFFFFF, str);
  }
  return (0);
}

int      key_hook (int keycode, t_gui *p)
{
  if(keycode == ECHAP)
    exit(1);
  loop_key_hook(p);
  return (0);
}

int     mouse_hook (int button, t_gui *p)
{
  if (button == 1)
  {
    if (p->pause == 0)
      p->pause = 1;
    else if (p->pause == 1)
      p->pause = 0;
  }
  loop_key_hook(p);
  return (0);
}

void     draw_title (t_gui *p)
{
  int     n;
  int     r;

  p->img2 = mlx_xpm_file_to_image(p->mlx, "fond.xpm", &n, &r);
  p->ret2 = mlx_get_data_addr(p->img, &(p->bits_per_pixel),
    &(p->size_line), &(p->endian));
}

void     init_gui(t_gui *p)
{
  p->pause = 0;
  p->r     = 0;
  p->v     = 0;
  p->b     = 0;
  p->map   = 0;
  p->map_x = 0;
  p->map_y = 0;
}


int     main (void)
{
  t_gui    *p;

  p = (t_gui*) malloc(sizeof(t_gui));
  init_gui(p);
  p->mlx = mlx_init();
  p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, "HELIOS FILLER");
  p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
  draw_title(p);
  mlx_hook(p->win, 2, 2, key_hook, p);
  mlx_mouse_hook(p->win, mouse_hook, p);
  loop_key_hook(p);
  mlx_loop_hook(p->mlx, loop_key_hook, p);
  free(p->map);
  mlx_loop(p->mlx);

  free(p);
  return (0);
}

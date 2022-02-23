#include <cairo.h>

void put_pixel(cairo_t* cr, int x, int y, float red, float blue, float green);
void translate_coord(cairo_t* cr, int point[2]);

int main (int argc, char* argv[argc+1]) {
  // create surface & canvas
  cairo_surface_t* surface =
    cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 240, 80);
  cairo_t* cr =
    cairo_create(surface);

  // draw on canvas
  for(int i = 0; i < 100; ++i) {
    put_pixel(cr, i, i, (float)i/100.0, 2 * (float)i/100.0, (float)i/100.0);
  }

  // save & cleanup
  cairo_destroy(cr);
  cairo_surface_write_to_png(surface, "test.png");
  cairo_surface_destroy(surface);

  return 0;
}

/* cairo implementation: draws a 1x1 rectangle */
void put_pixel(cairo_t* cr, int x, int y, float red, float blue, float green) {
  // convert math-coord to canvas-coord
  int point[2] = { 
    [0] = x,
    [1] = y
  };
  translate_coord(cr, point);

  // create a closed subpath
  cairo_rectangle(cr, point[0], point[1], 1, 1);
  // set color to black
  cairo_set_source_rgb(cr, red, green, blue);
  // fill in the path
  cairo_fill(cr);
}

void translate_coord(cairo_t* cr, int point[2]) {
  cairo_surface_t* surface = cairo_get_target(cr);
  int width = cairo_image_surface_get_width(surface);
  int height = cairo_image_surface_get_height(surface);

  point[0] = width/2 + point[0];
  point[1] = height/2 - point[1];
}

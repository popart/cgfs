#include <cairo.h>

void put_pixel(cairo_t* cr, int x, int y);

int main (int argc, char* argv[argc+1]) {
  // create surface & canvas
  cairo_surface_t* surface =
    cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 240, 80);
  cairo_t* cr =
    cairo_create(surface);

  // draw on canvas
  put_pixel(cr, 120, 40);

  // save & cleanup
  cairo_destroy(cr);
  cairo_surface_write_to_png(surface, "test.png");
  cairo_surface_destroy(surface);

  return 0;
}

/* cairo implementation: draws a 1x1 rectangle */
void put_pixel(cairo_t* cr, int x, int y) {
  // create a closed subpath
  cairo_rectangle(cr, x, y, 1, 1);
  // set color to black
  cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);
  // fill in the path
  cairo_fill(cr);
}

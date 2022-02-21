#include <cairo.h>

int main (int argc, char *argv[]) {
  // create canvas
  cairo_surface_t *surface =
    cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 240, 80);
  cairo_t *cr =
    cairo_create(surface);

  /* drawing a rectangle
     creates a fuzzy dot? (at the right point)
     I think it's treating pixels as samples or something
   */

  // creates a closed subpath
  cairo_rectangle(cr, 120, 40, 1, 1);
  // set color to black
  cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);
  // fill in the path
  cairo_fill(cr);

  // destroy canvas
  cairo_destroy(cr);
  cairo_surface_write_to_png(surface, "test.png");
  cairo_surface_destroy(surface);

  return 0;
}

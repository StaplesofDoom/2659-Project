#ifndef RASTER_H
#define RASTER_H

#include "types.h"

void plot_pixel(char *base, int x, int y);
void plot_bitmap(char *base, int x, int y, UINT16 *bitmap, unsigned height);
void plot_vertical(char *base, int x, int y, int len);
void plot_horizontal(char *base, int x, int y, int len);
void clear_screen(char *base);

#endif

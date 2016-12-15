#ifndef RASTER_H
#define RASTER_H

#include <osbind.h>
#include <string.h>

#include "types.h"
#include "clr_qk.h"
#include "set_area.h"
#include "bitmaps.h"

#define INVADER_HEIGHT 16
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400

void plot_pixel(char *base, int x, int y);
void clear_area(unsigned long *base, int x0, int y0, int x1, int y1); /* does not work, clear screen is used for now */
void plot_clear32 (unsigned long *base, int x, int y, unsigned height);
void plot_bitmap32 (unsigned long *base, int x, int y, UINT32 *bitmap, unsigned height);
void plot_bitmap16 (unsigned int *base, int x, int y, UINT16 *bitmap, unsigned height);
void plot_bitmap8 (unsigned char *base, int x, int y, UINT8 *bitmap, unsigned height);
void clear_screen();
void clear_full();
void set_ground();
void set_splash(UINT8 *base, const UINT8 *splash);
void plot_select(UINT32 *base, int pos);

#endif

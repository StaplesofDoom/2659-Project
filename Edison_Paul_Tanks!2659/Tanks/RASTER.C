/* ============================================================================
Name: Raster.c
Purpose: Holds all functions that draws to the screen
============================================================================ */

#include "raster.h"
/*
Function Summary:

plot_pixel: Plots a single pixel at the given X and Y coordinate, given the
			supplied pointer to the frame buffer.

plot_bitmap16: Plots a 16-pixel wide bitmap of the callers choice, at the given
			 X and Y coordinates with the supplied frame buffer pointer.
			 
clear_screen: Clears the screen of all pixels, must be supplied a frame buffer pointer.

Screen width and height constants are set at 640 and 400 respectively to ensure
correct dimensions

*/

/* ============================================================================
Name: Plot_clear32
Purpose: clears a 32x32 area
============================================================================ */
void plot_clear32 (unsigned long *base, int x, int y, unsigned height){
	UINT32 j;
	for(j = 0; j < height; j++){
		*(base + (y+j) * 20 + (x >> 5)) &= 0xFFFFFFFF << 32 - (x & 31); 
		*(base+1 + (y+j) * 20 + (x >> 5)) &= 0xFFFFFFFF >> (31 & x); 
	}                 /* 32bits, x shifts right by 5 2^5 = 32. */
}

/* ============================================================================
Name: Plot_bitmap32
Purpose: plots a 32 width bitmaps
============================================================================ */
void plot_bitmap32 (unsigned long *base, int x, int y, UINT32 *bitmap, unsigned height){
	UINT32 j;
	for(j = 0; j < height; j++){
		*(base + (y+j) * 20 + (x >> 5)) |= bitmap[j] >> (31 & x); 
		*(base+1 + (y+j) * 20 + (x >> 5)) |= bitmap[j] << 32 - (x & 31); 
	}                 /* 32bits, x shifts right by 5 2^5 = 32. */
}

/* ============================================================================
Name: Plot_bitmap16
Purpose: plots a 16 width bitmap, mainly used fonts
============================================================================ */
void plot_bitmap16 (unsigned int *base, int x, int y, UINT16 *bitmap, unsigned height){
	UINT16 j;
	for(j = 0; j < height; j++){
		*(base + (y+j) * 40 + (x >> 4)) |= bitmap[j] >> (15 & x)+1; 
		*(base+1 + (y+j) * 40 + (x >> 4)) |= bitmap[j] << 16 - (x & 15); 
	}                 
}

/* ============================================================================
Name: Plot_bitmap8
Purpose: plots a 8 width bitmap
============================================================================ */
void plot_bitmap8 (unsigned char *base, int x, int y, UINT8 *bitmap, unsigned height){
	UINT8 j;
	for(j = 0; j < height; j++){
		*(base + (y+j) * 80 + (x >> 3)) |= bitmap[j] >> (7 & x);
		*(base + (y+j) * 80 + (x >> 3)) |= bitmap[j] << 7 - (x & 7);
	}
}

/* ============================================================================
Name: set_splash
Purpose: draws the splash screen
============================================================================ */
void set_splash(UINT8 *base, const UINT8 *splash){
	memcpy(base, splash, (long)32000);
}
/* ============================================================================
Name: Plot_select
Purpose: plots a select icon depending on the position and clears the two other spots.
============================================================================ */
void plot_select(UINT32 *base, int pos){
	if (pos == 0){
		
		plot_bitmap32(base, 15, 124, select, 32); 
		plot_clear32 (base, 15, 184, 32);
		plot_clear32 (base, 15, 244, 32);
	} else if (pos == 1){
		plot_clear32 (base, 15, 124, 32);
		plot_bitmap32(base, 15, 184, select, 32);
		plot_clear32 (base, 15, 244, 32);
	} else if (pos == 2){
		plot_clear32 (base, 15, 124, 32);
		plot_clear32 (base, 15, 184, 32);
		plot_bitmap32(base, 15, 244, select, 32);
	}
}

void clear_screen(long *base){
	clr_qk(base);
}

void clear_full(long *base){
	clr_full(base);
}

void set_ground(long *base){
	set_area(base);
}
#include "raster.h"
#include <osbind.h>

#define INVADER_HEIGHT 16
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400
/*
Function Summary:

plot_pixel: Plots a single pixel at the given X and Y coordinate, given the
			supplied pointer to the frame buffer.
			
plot_horizonal, plot_vertical: Plots a line of the appropriate direction at the given
							   x and y coordinates as well as the supplied frame buffer
							   pointer.

plot_bitmap: Plots a 16-pixel wide bitmap of the callers choice, at the given
			 X and Y coordinates with the supplied frame buffer pointer.
			 
clear_screan: Clears the screen of all pixels, must be supplied a frame buffer pointer.

Screen width and height constants are set at 640 and 400 respectively to ensure
correct dimensions

*/


/*
UINT16 invader_bitmap[INVADER_HEIGHT] = {
0x0000,
0x0810,
0x0810,
0x0420,
0x0240,
0x1FF8,
0x2004,
0x4662,
0x4020,
0x43C2,
0X2424,
0X1008,
0X0FF0,
0X0240,						Sample bitmap for testing TO BE REMOVED
0X0E70,
0X0000
};
*/

void plot_pixel(char *base, int x, int y)
{
if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
	*(base + y * 80 +(x >> 3)) |= 1 << 7 - (x & 7);
}

void plot_bitmap (char *base, int x, int y, UINT16 *bitmap, unsigned height)
{
	UINT16 j;
	if(x < SCREEN_WIDTH && x >= 0 && y < SCREEN_HEIGHT && y >= 0){
		for(j = 0; j < height; j++){
			*(base + (y+j) * 40 + (x >> 4)) |= bitmap[j];
		}                 /* 16bits, x shifts right by 4 2^4 = 16. */
	}
}

void plot_vertical(char *base, int x, int y, int len){
	
	int i;
	
	for(i = 0; i < len; i++ )
			plot_pixel(base,x,(y+i));
	
}

void plot_horizonal(char *base, int x, int y, int len){
	
	int i;
	
	for(i = 0; i < len; i++)
		plot_pixel(base,(x+i),y);
	
}

void clear_screan(char *base){
	int j;
	

}

int main(){
	char *base = Physbase();
	int i;
	
	for(i = 0; i < 5; i++)
	plot_vertical(base,0 + i,100,400);

	for(i = 0; i < 5; i++)
		plot_vertical(base, 634+i,100, 400);
	
	for(i = 0; i < 5; i++)
		plot_horizonal(base, 0, 0 + i, 640 );
	
	for(i = 0; i < 5; i++)
		plot_horizonal(base, 0, 394 + i, 640);
	
	
	
	return 0;
}

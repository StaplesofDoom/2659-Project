#define SCREEN_HEIGHT 400
#define SCREEN_WIDTH 640

#include <osbind.h>
#include <stdio.h>

void plot_pixel(char *base, int x, int y){

	if( x>=0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
		*(base + y * 80 + (x >> 3)) |= 1 << 7 - (x & 7);
}
int main(){
	int x;
	char *base = Physbase();
	char a;
	
	plot_pixel(base, 25, 25);
	plot_pixel(base, 26, 26);
	plot_pixel(base, 27, 27);


	for(x = 0; x < 200; x = x + 1){
	plot_pixel(base, x, x);
}
	scanf("%s" , a);


	return 0;

}

#include "effects.h"

/* This module contains all the code to implement sound effects. It is technically game-independent, though
clearly it is tailored to this specific game.  */


void play_explosion(){
	
 	set_noise(0x1F); 
 	enable_channel(1,0,1);
/* 	enable_channel(1,0,1);
	enable_channel(2,0,1);  */
 	set_volume(1,0x10);
/* 	set_volume(1,0x10);
	set_volume(2,0x10);  */
	set_envelope(0x00, 0x38); 
}
void play_shot_fired(){
	
	set_noise(0x0F);
	enable_channel(1,0,1);
/* 	enable_channel(1,0,1);
	enable_channel(2,0,1); */ 
	set_volume(1,0x10);
/* 	set_volume(1,0x10);
	set_volume(2,0x10); */
	set_envelope(0x00,0x10);
	
	
}

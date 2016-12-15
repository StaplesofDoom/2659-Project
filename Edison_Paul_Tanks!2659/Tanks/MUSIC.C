#include "MUSIC.H"

/* This module handles all song manipulation. It is game-independent, however it is dependent on
the PSG module. Contains a song in the form of an array of tone settings, as well as a function to start
music and update music as appropriate. */



int music_notes[32] = {
	506, 414, 379, 284, 310, 379,			/* Divided by measures */
	284, 696, 253, 310, 
	426,
	142,
	142, 310, 348, 414, 414, 348,
	310, 414, 414, 0,
	142, 310, 348, 414, 414, 348,			
	310, 414, 414, 0
};
void start_music(){
	
 	write_psg(0, 0x00);				/* Sets ALL registers to 0 to ensure a clean start */
	write_psg(1, 0x00);
	write_psg(2, 0x00);
	write_psg(3, 0x00);
	write_psg(4, 0x00);
	write_psg(5, 0x00);
	write_psg(6, 0x00);
	write_psg(7, 0x00);
	write_psg(8, 0x00);
	write_psg(9, 0x00);
	write_psg(10, 0x00);
	write_psg(11, 0x00);
	write_psg(12, 0x00);
	write_psg(13, 0x00);
	write_psg(14, 0x00);
	write_psg(15, 0x00); 
	
	set_tone(0, music_notes[0]);
	enable_channel(0,1,0);
	set_volume(0, 0x06);
	
}

void update_music(UINT32 time_elapsed){					/* Updates to the next note in the array */
	 
	if(time_elapsed % 3 == 0)
		set_tone(0, music_notes[(time_elapsed / 3)]);
}
#include "psg.h"

/* This module contains game-independent methods for writing and modifying the on-board
Programmable Sound Generator on the Atari ST. Offers function wrappers for modifying all
registers on the PSG. */

	
void write_psg(int reg, UINT8 val){
	
	volatile char *PSG_reg_select = 0xFF8800;
	volatile char *PSG_reg_write  = 0xFF8802;
	
	  long old_ssp = Super(0);  

	if(reg <= 15 && reg >= 0){			/* Only 16 registers on, so error checking for invalid input */
	
			*PSG_reg_select = reg;
			*PSG_reg_write = val;	
	}
	
 	 Super(old_ssp);  
}

void set_tone(int channel, int tuning){
	
	if(channel >= 0 && channel <= 2){			/* Takes the lower byte of the incoming 12-bit number */
		if(channel == 0){						/* for the fine tuning, and the highest 4 bits for the */
			write_psg(0, (UINT8)tuning);		/* rough tuning */
			write_psg(1, (tuning >> 8));
		}
		else if(channel == 1){
			write_psg(3, (tuning >> 8));
			write_psg(2, (UINT8)tuning);
		}
		else if(channel == 2){
			write_psg(5, (tuning >> 8));
			write_psg(4, (UINT8)tuning);
		}
	}
}

void set_volume(int channel, int volume){
		
	if(channel >= 0 && channel <= 2){			/* Channel 0 is A, 1 is B and 2 is C */
		if(channel == 0){
			write_psg(8, volume);
		}
		else if(channel == 1){
			write_psg(9, volume);
		}
		else if(channel == 2){
			write_psg(10, volume);
		}
	}
}

void enable_channel(int channel, int tone_on, int noise_on){
	
 	if(channel >= 0 && channel <= 2){				/* Channel 0 is A, 1 is B and 2 is C */
		if(channel == 0){
			if(tone_on == 1 && noise_on == 1)
				write_psg(7, 0x09);
			else if(tone_on == 0 && noise_on == 1)
				write_psg(7, 0x08);
			else if(tone_on == 1 && noise_on == 0)
				write_psg(7, 0x3E);
			else
				write_psg(7,0x00);	
		}
		else if(channel == 1){
			if(tone_on == 1 && noise_on == 1)
				write_psg(7, 0x12);
			else if(tone_on == 0 && noise_on == 1)
				write_psg(7, 0x2E);
			else if(tone_on == 1 && noise_on == 0)
				write_psg(7, 0x02);
			else if(tone_on == 0 && tone_on == 0)
				write_psg(7,0x00);	
		}
		else if(channel == 2){
			if(tone_on == 1 && noise_on == 1)
				write_psg(7, 0x24);
			else if(tone_on == 0 && noise_on == 1)
				write_psg(7, 0x20);
			else if(tone_on == 1 && noise_on == 0)
				write_psg(7, 0x04);
			else if(tone_on == 0 && tone_on == 0)
				write_psg(7,0x00);	
		}
	} 
}

void stop_sound(){
	
	set_volume(0, 0x00);				/* Sets the Volume on each channel to 0 */
	set_volume(1, 0x00);
	set_volume(2, 0x00);
	
}

void set_noise(int tuning){

	write_psg(6, tuning);
}

void set_envelope(int shape, unsigned int sustain){
	
	write_psg(13, shape);
	write_psg(11, (sustain >> 8));
	write_psg(12, (UINT8)sustain);
}

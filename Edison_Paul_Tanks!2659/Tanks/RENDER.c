/* ============================================================================
Name: Render.C
Purpose: Draws a screen of the game with the current X and Y values of each items
in a specific base.
============================================================================ */

#include "render.h"

/* ============================================================================
Name: out_screen
Purpose: Draws the whole screen in a base while in game.
============================================================================ */
void out_screen(UINT8 *base, model *game){
	int i;
	int spacer;
	int bitmap_right_one = (game->One.aim_angle/14)+7;
	int bitmap_left_one = game->One.aim_angle/14;
	int bitmap_right_two = (game->Two.aim_angle/14)+7;
	int bitmap_left_two = game->Two.aim_angle/14;
	
	clear_screen((unsigned long*)base);
	set_ground((unsigned long*)base);

	/* Player 1*/
	if(game->One.direction == 'R'){
	plot_bitmap32((unsigned long*)base, game->One.x, game->One.y, &p1[bitmap_right_one << 5], 32);
	} else {
	plot_bitmap32((unsigned long*)base, game->One.x, game->One.y, &p1[bitmap_left_one << 5], 32);		
	}
	
	if (game->p1_shell.on_screen == 1){
		plot_bitmap8((unsigned char*)base, game->p1_shell.x, game->p1_shell.y, shell, 8);
	}

	/* Player 2 */
	if(game->Two.direction == 'R'){
	plot_bitmap32((unsigned long*)base, game->Two.x, game->Two.y, &p2[bitmap_right_two << 5], 32);
	} else {
	plot_bitmap32((unsigned long*)base, game->Two.x, game->Two.y, &p2[bitmap_left_two << 5], 32);		
	}
	
	if (game->p2_shell.on_screen == 1){
		plot_bitmap8((unsigned char*)base, game->p2_shell.x, game->p2_shell.y, shell, 8);
	}

		
	/* health */
	for (i = 0; i < game->p1_health.amount_of_health; i++){
		plot_bitmap32((unsigned long*)base, (game->p1_health.x+(i*36)), game->p1_health.y, health, 32);
	}
	for (i = 0; i < game->p2_health.amount_of_health; i++){
		plot_bitmap32((unsigned long*)base, (game->p2_health.x+(i*36)), game->p2_health.y, health, 32);
	}
	
	/* round counter */
	spacer = game->counter.x; 
	plot_bitmap16 ((unsigned int *)base, spacer, game->counter.y, &fonts[(game->counter.player_one_score + ('0'-' ')) << 5], 32);
	plot_bitmap16 ((unsigned int *)base, spacer+32, game->counter.y, &fonts[('-' - ' ') << 5], 32);
	plot_bitmap16 ((unsigned int *)base, spacer+64, game->counter.y, &fonts[(game->counter.player_two_score + ('0'-' ')) << 5], 32);
	
}

/* ============================================================================
Name: end_screen
Purpose: displays an end game screen which shows the final score (best out of 3)
and the winner.
============================================================================ */
void end_screen(UINT8 *base, model *game){
	clear_screen(base);
	
	plot_bitmap16 ((unsigned int *)base, 208, 163, &fonts[('P'-' ') << 5], 32);
	plot_bitmap16 ((unsigned int *)base, 224, 163, &fonts[('L'-' ') << 5], 32);
	plot_bitmap16 ((unsigned int *)base, 240, 163, &fonts[('A'-' ') << 5], 32);
	plot_bitmap16 ((unsigned int *)base, 256, 163, &fonts[('Y'-' ') << 5], 32);
	plot_bitmap16 ((unsigned int *)base, 272, 163, &fonts[('E'-' ') << 5], 32);
	plot_bitmap16 ((unsigned int *)base, 288, 163, &fonts[('R'-' ') << 5], 32);
	plot_bitmap16 ((unsigned int *)base, 304, 163, &fonts[(' '-' ') << 5], 32);
	
	if(game->counter.player_one_score > game->counter.player_two_score){
	plot_bitmap16 ((unsigned int *)base, 320, 163, &fonts[1 + ('0'-' ') << 5], 32);
	}else{
	plot_bitmap16 ((unsigned int *)base, 320, 163, &fonts[2 + ('0'-' ') << 5], 32);		
	}
	plot_bitmap16 ((unsigned int *)base, 336, 163, &fonts[(' '-' ') << 5], 32);
	plot_bitmap16 ((unsigned int *)base, 352, 163, &fonts[('W'-' ') << 5], 32);
	plot_bitmap16 ((unsigned int *)base, 368, 163, &fonts[('I'-' ') << 5], 32);
	plot_bitmap16 ((unsigned int *)base, 384, 163, &fonts[('N'-' ') << 5], 32);
	plot_bitmap16 ((unsigned int *)base, 400, 163, &fonts[('S'-' ') << 5], 32);
	plot_bitmap16 ((unsigned int *)base, 416, 163, &fonts[('!'-' ') << 5], 32);
	
	plot_bitmap16 ((unsigned int *)base, game->counter.x, 199, &fonts[(game->counter.player_one_score + ('0'-' ')) << 5], 32);
	plot_bitmap16 ((unsigned int *)base, game->counter.x+32, 199, &fonts[('-' - ' ') << 5], 32);
	plot_bitmap16 ((unsigned int *)base, game->counter.x+64, 199, &fonts[(game->counter.player_two_score + ('0'-' ')) << 5], 32);
}
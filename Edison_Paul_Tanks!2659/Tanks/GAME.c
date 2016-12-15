#include "game.h"

/* This module contains all game-dependent code, and includes the main game loop,
timing and scorekeeping, as well as the menu system. */



int timer = 0;
UINT8 render_request = 1;

int main(){	
	UINT8 *base;	
	UINT8 *base2 = &buffer;
	
	long old_ssp;
	int gameOver, random = 0, counter = 0, bool = 0, ai_shot_timer = 0,
	ai_shot_counter = 0, music_counter = 0, zeroHealth = FALSE, round,
	toggle = FALSE, select, input, move_counter = 0;
	
	Vector orig_vector, IKBD_vector;
	
	model gameModel;
	model *game = &gameModel;
	
	/* Setting up bases */
	old_ssp = Super(0);
	base = get_video_base();
	Super(old_ssp);
	base2 = (UINT8 *)((UINT32) base2 + (256 - (UINT32)base2 & 255));

	initialize_score(game);
	clear_full(base);
	
	/* Menu Screen/ Splash Screen =================================================================*/
	set_splash((UINT8*)base, (UINT8*)splash);
	select = 0;
	plot_select((UINT32 *)base, select);
	orig_vector = install_vector(VBL,vbl_isr);
	IKBD_vector = install_vector(IKBD, IKBD_isr);
	
	while (input != 28){
	/* 	if(buffer_empty == 1) */
			input = dequeue();
			
		switch (select){
			case 0:
				if (input == 0x50){
					select = 1;
					} 
				plot_select((UINT32 *)base, select);
			break;			
			case 1:
				if (input == 0x48){
					select = 0;
				} else if (input == 0x50){
					select = 2;
				}
				plot_select((UINT32 *)base, select);	
			break;
			case 2:
				if (input == 0x48){
					select = 1;
				}
				plot_select((UINT32 *)base, select);	
			break;
		}
	}
	
	/* End of Menu Screen =========================================================================*/
	
	/* If 1 Player is selected. Main game loop. ===================================================*/
	if (select == 0){
	 	
		round = 1;
		
		while (round <= NUM_ROUNDS){
			initialize_model(game);
			start_music(); 
			out_screen(base,game); 
			
			gameOver = FALSE;	
			while(gameOver == FALSE){
				
				/* Processing user input */
 				/* if(buffer_empty == 1){ */
					input = dequeue();
					switch (input){
						case 0x1E:
							if(request_tank_move(game, 1) == TRUE){
								move_tank(game, 'L', 1);
							}
						break;
					
						case 0x20:
							if(request_tank_move(game, 1) == TRUE){
								move_tank(game, 'R', 1);
							}
						break;
					
						case 0x11: 
							if(request_turret_move(game, 1, 'U') == TRUE){
								move_turret(game, 1, 'U');
							}
						break;
						
						case 0x1F:				
							if(request_turret_move(game, 1, 'D') == TRUE){
								move_turret(game, 1, 'D');
							}
						break;
					
						case 0x39:
							if(request_fire(game, 1) == TRUE){
								initialize_shell(game, 1);
								game->p1_shell.on_screen = 1;
						 		play_shot_fired();
								
								}
						break;		
						
						case 0x10:
							gameOver = TRUE;
							round = 4;
						break;
					}
		/* 		}  */
				
				if(render_request >= 1){							/* Any and all timer related operations start here */
					counter += 1;
					ai_shot_timer += 1;
					ai_shot_counter += 1;					/* Arbitrary timers for synchronous events */
					music_counter += 1;
					move_counter += 1;
				
					if(counter == 1){									/* Processing for any waiting events to update */
						if(game->p1_shell.on_screen == 1){
							if(request_shell_move(game, 1) == TRUE){
								move_shell(game, 1);
								if(check_shell_collisions(game, 1) == TRUE){
									zeroHealth = update_health(game, 2);
							 		play_explosion();
								}
							}
						}
						counter = 0;
					}
					if(ai_shot_counter == 35){
						ai_shot(game);
						random = rand() % 20;
						if(random % 7 == 0){
							if(request_turret_move(game, 2, 'U') == TRUE){
								move_turret(game, 2, 'U');
							}
						}
						else if(random % 5 == 0){
							if(request_turret_move(game, 2, 'D') == TRUE){
								move_turret(game, 2, 'D');
							}
						}
						ai_shot_counter = 0;
					}
					
					if(move_counter == 20)
						if(request_tank_move(game, 2) == TRUE){
							move_tank(game, 'L', 2);
							move_counter = 0;
						}
					
					
					if(ai_shot_timer == 1){
						if(game->p2_shell.on_screen == TRUE){
							if(request_shell_move(game, 2) == TRUE){
								move_shell(game, 2);
								if(check_shell_collisions(game, 2) == TRUE){
									zeroHealth = update_health(game, 1);
								 	play_explosion();
								}
							}
						}
						ai_shot_timer = 0;
					}   
					
				 	update_music(music_counter);
					if (timer >= 500){
						music_counter = 0;
						timer = 0;
					}
			
					if (toggle == FALSE){
						toggle = TRUE;
						out_screen(base,game);
						old_ssp = Super(0);
					
						set_video_base(base);
						Super(old_ssp);
					}else {
						toggle = FALSE;
						out_screen(base2,game);
					
						old_ssp = Super(0);
						set_video_base(base2);
						Super(old_ssp);
					}
					render_request = 0;
				}
				if (zeroHealth == TRUE){
					gameOver = TRUE;
					round += 1;
					zeroHealth = FALSE;
					if (game->p1_health.amount_of_health == 0)
						game->counter.player_two_score += 1;
					else
						game->counter.player_one_score += 1; 
				}
			}
		/*======================= End of the main game loop ============================================*/
			out_screen(base, game);
			end_screen(base,game);

			old_ssp = Super(0);				/*Resetting old vectors and proper video bases */
			set_video_base(base);
			Super(old_ssp);
			stop_sound();
		}
		install_vector(VBL, orig_vector);
		install_vector(IKBD, IKBD_vector);
	
	}else {
		clear_full(base);
		install_vector(VBL, orig_vector);
		install_vector(IKBD, IKBD_vector);
	}
	return 0;
}
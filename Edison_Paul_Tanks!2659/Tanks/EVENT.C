#include "event.h"

/* This module contains all the event handling and checking for the Tanks! game. Checking collisions, and
requests for movement and firing are all here, as well as the code for the AI shooting. */


/* Requesters and Asynchronous  */

int request_tank_move(model *gameModel, int playerNumber){
	int good = TRUE;
	if(playerNumber == 1){
		good = check_tank_collisions(gameModel,1);
	}
	else{
		good = check_tank_collisions(gameModel, 2);
	}
	return good;
}

int request_turret_move(model *gameModel, int playerNumber, char direction){
	int good;
	
	if(playerNumber == 1){
			if(direction == 'U'){
				if((gameModel->One.aim_angle + 14) <= 56){		/* Maximum angle and minimum angle checking */
					good = TRUE;
				}
				else{
					good = FALSE;
				}
			}
			else{
				if((gameModel->One.aim_angle - 14) >= 0){
					good = TRUE;
				}
				else{
					good = FALSE;
				}
			}
		}
	if(playerNumber == 2){
		if(direction == 'U'){
			if((gameModel->Two.aim_angle + 14) <= 56){			/*Max and Min angle for AI set a bit lower to be more consistent */
				good = TRUE;
			}
			else{
				good = FALSE;
			}
		}
		else{
			if((gameModel->Two.aim_angle - 14) >= 28){
				good = TRUE;
			}
			else{
				good = FALSE;
			}
		}
	}
			return good;
	}

int request_fire(model *gameModel, int playerNumber){
	int good;
	
	if(playerNumber == 1){
		if(gameModel->p1_shell.on_screen == 1){
			good = FALSE;
		}
		else{
			good = TRUE;
		}
	}
	else{
		if(gameModel->p2_shell.on_screen == 1){
			good = FALSE;
		}
		else{
			good = TRUE;
		}
	}
	return good;
}

int request_shell_move(model *gameModel, int playerNumber){
	int good = TRUE;
	
	if(playerNumber == 1){

		if(gameModel->p1_shell.x + gameModel->p1_shell.x_velocity >= 639 || 
			gameModel->p1_shell.x - gameModel->p1_shell.x_velocity <= 0  || 
			gameModel->p1_shell.y + gameModel->p1_shell.y_velocity >= 300 ||
			 gameModel->p1_shell.y - gameModel->p1_shell.y_velocity <= 0) {
			good = FALSE;
			gameModel->p1_shell.on_screen = 0;
		}
	}
	else{
		if(gameModel->p2_shell.x + gameModel->p2_shell.x_velocity >= 639 || 
			gameModel->p2_shell.x - gameModel->p2_shell.x_velocity <= 0  || 
			gameModel->p2_shell.y + gameModel->p2_shell.y_velocity >= 300 ||
			 gameModel->p2_shell.y - gameModel->p2_shell.y_velocity <= 0 ){
			good = FALSE;
			gameModel->p2_shell.on_screen = 0;
		}
	}
	
	return good;
}

void ai_shot(model *gameModel){
	if(gameModel->p2_shell.on_screen == 0){
		initialize_shell(gameModel, 2);
		gameModel->p2_shell.on_screen = 1;
	 	play_shot_fired();
	}
}
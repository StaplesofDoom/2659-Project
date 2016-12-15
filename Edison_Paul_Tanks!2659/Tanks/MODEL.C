#include <osbind.h>
#include <stdio.h>

#include "model.h"
/* This module contains everything needed to run the backend of a Tanks! game. 
All of the attributes of every object in the game are kept in structures, most are further
collected into one superstructure simply termed "model"

This module also contains methods for updating and effecting changes onto the model.

This model is also game INDEPENDENT.  */

/* Initializers */

void initialize_model(model *gameModel){
	
	gameModel->One.x = 80;
	gameModel->One.y = 268;
	gameModel->One.direction = 'R';
	gameModel->One.delta_x = 4;
	gameModel->One.delta_y = 8;
	gameModel->One.aim_angle = 0;

	gameModel->Two.x = 528;
	gameModel->Two.y = 268;
	gameModel->Two.direction = 'L';
	gameModel->Two.delta_x = 4;
	gameModel->Two.delta_y = 8;
	gameModel->Two.aim_angle = 45;
	
	gameModel->p1_health.x = 8;
	gameModel->p1_health.y = 8;
	
	gameModel->p1_health.amount_of_health = 3;

	gameModel->p2_health.x = 528;
	gameModel->p2_health.y = 8;
	
	gameModel->p2_health.amount_of_health = 3;

	
	gameModel->floor.x = 100;
	gameModel->floor.y = 300;
	
	gameModel->p1_shell.on_screen = 0;
	gameModel->p2_shell.on_screen = 0;
}

void initialize_score(model *gameModel){
	gameModel->counter.x = 280;
	gameModel->counter.y = 8;
	gameModel->counter.player_one_score = 0;
	gameModel->counter.player_two_score = 0;
}

void initialize_shell(model *gameModel, int playerNumber){

	if(playerNumber == 1){
		if(gameModel->One.direction == 'R'){
				gameModel->p1_shell.x = (gameModel->One.x) + 33;
				gameModel->p1_shell.y = gameModel->One.y;
			}
			else{
				gameModel->p1_shell.x = gameModel->One.x;
				gameModel->p1_shell.y = gameModel->One.y;
			}
		gameModel->p1_shell.x_velocity = SHELL_VELOCITY;
		gameModel->p1_shell.y_velocity = SHELL_VELOCITY - gameModel->One.aim_angle + 5;

		}
	
	else{
		if(gameModel->Two.direction == 'R'){
			gameModel->p2_shell.x = (gameModel->Two.x) + 33;
			gameModel->p2_shell.y = gameModel->Two.y;
		}
		else{
			gameModel->p2_shell.x = gameModel->Two.x;
			gameModel->p2_shell.y = gameModel->Two.y;
		}
		gameModel->p2_shell.x_velocity = SHELL_VELOCITY;
		gameModel->p2_shell.y_velocity = SHELL_VELOCITY - gameModel->Two.aim_angle + 5;

	}
	
	
}

/* Behaviour functions (Synchronous Events) */

/* This function is used to calculate all physics for a moving projectile, given a model and which
	shell is to be updated. */

int physics_calculator(model *gameModel,int playerNumber){
	int yVelocity;
	
	if(playerNumber ==  1){
		yVelocity = (gameModel->p1_shell.y_velocity) + GRAVITY;
	}
	else{
		yVelocity = (gameModel->p2_shell.y_velocity) + GRAVITY;
	}
	
	return yVelocity;
}

/* The following two methods are used to check whether the tank, and tank shell, collide with
any geometry on the screen, including each other, the floor, the walls and the ceiling. */

int check_shell_collisions(model *gameModel, int playerNumber){
	int i = 0;
	int j = 0;
	int good = FALSE;
	
	if(playerNumber == 1){
		for(i = 0; i < 32; i++){
			for(j = 0; j < 32; j++){
				if(gameModel->p1_shell.x == gameModel->Two.x+i && 
				   gameModel->p1_shell.y == gameModel->Two.y+j){
					good = TRUE;
				}
			}
		}
	}
	else{
		for(i = 0; i < 32; i++){
			for(j = 0; j < 32; j++){
				if(gameModel->p2_shell.x == gameModel->One.x+i && 
				   gameModel->p2_shell.y == gameModel->One.y+j){
					good = TRUE;
				}
			}
		}
	}	

	return good;
}

int check_tank_collisions(model *gameModel,int playerNumber){
	int good = TRUE;
	
	if(playerNumber == 1){
		if(gameModel->One.x + gameModel->One.delta_x >= gameModel->Two.x ||
			gameModel->One.x - gameModel->One.delta_x <= 0){
				good = FALSE;
				if(gameModel->One.x - gameModel->One.delta_x <= 0){
					gameModel->One.x += 8;
				}
				else if(gameModel->One.x + (gameModel->One.delta_x + 32) >= gameModel->Two.x - 32){
					gameModel->One.x -= 8;
				}
		}
	}
	
	return good;
}
void move_tank(model *gameModel,char direction, int playerNumber){
	if(playerNumber == 1){
		if(direction == 'R'){
			gameModel->One.old_x = gameModel->One.x;
			gameModel->One.x += gameModel->One.delta_x;
			gameModel->One.direction = 'R';
		}
		else{
			gameModel->One.old_x = gameModel->One.x;
			gameModel->One.x -= gameModel->One.delta_x;
			gameModel->One.direction = 'L';
		}
	}
	else{
			if(direction == 'R'){
			gameModel->Two.old_x = gameModel->Two.x;
			gameModel->Two.x += gameModel->Two.delta_x;
			gameModel->Two.direction = 'R';
		}
		else{
			gameModel->Two.old_x = gameModel->Two.x;
			gameModel->Two.x -= gameModel->Two.delta_x;
			gameModel->Two.direction = 'L';
		}
	}	
}

void move_turret(model *gameModel, int playerNumber, char direction){
	if(playerNumber == 1){
		if(direction == 'U'){
			gameModel->One.aim_angle += 14;
		}
		else{
			gameModel->One.aim_angle -= 14;
		}
	}
	else{
		if(direction == 'U'){
			gameModel->Two.aim_angle += 14;
		}
		else{
			gameModel->Two.aim_angle -= 14;
		}
	}
}

void move_shell(model *gameModel,int playerNumber){
	int velocity;
	
	if(playerNumber == 1 && gameModel->p1_shell.on_screen == 1){
		if(gameModel->One.direction == 'R'){
			velocity = physics_calculator(gameModel,playerNumber);
			gameModel->p1_shell.y_velocity = velocity;
			gameModel->p1_shell.old_x = gameModel->p1_shell.x;
			gameModel->p1_shell.old_y = gameModel->p1_shell.y;
			gameModel->p1_shell.x += gameModel->p1_shell.x_velocity;
			gameModel->p1_shell.y += gameModel->p1_shell.y_velocity;
		}
		else{
			velocity = physics_calculator(gameModel,playerNumber);
			gameModel->p1_shell.y_velocity = velocity;
			gameModel->p1_shell.old_x = gameModel->p1_shell.x;
			gameModel->p1_shell.old_y = gameModel->p1_shell.y;
			gameModel->p1_shell.x -= gameModel->p1_shell.x_velocity;
			gameModel->p1_shell.y += gameModel->p1_shell.y_velocity;
		}
	}
	else if(gameModel->p2_shell.on_screen == 1){
			if(gameModel->Two.direction == 'R'){
			velocity = physics_calculator(gameModel, playerNumber);
			gameModel->p2_shell.y_velocity = velocity;
			gameModel->p2_shell.old_x = gameModel->p2_shell.x;
			gameModel->p2_shell.old_y = gameModel->p2_shell.y;		
			gameModel->p2_shell.x += gameModel->p2_shell.x_velocity;
			gameModel->p2_shell.y += gameModel->p2_shell.y_velocity;
		}
		else{
			velocity = physics_calculator(gameModel, playerNumber);
			gameModel->p2_shell.y_velocity = velocity;
			
			gameModel->p2_shell.old_x = gameModel->p2_shell.x;
			gameModel->p2_shell.old_y = gameModel->p2_shell.y;
			gameModel->p2_shell.x -= gameModel->p2_shell.x_velocity;
			gameModel->p2_shell.y += gameModel->p2_shell.y_velocity;
		}
	}
}
/* 
The following functions decrement or increment the health and score of a player, respectively.
They return the modified score, so checking can be done elsewhere for a game ending.
 */

int update_score(model *gameModel, int playerNumber){
	int score;
	if(playerNumber == 1){
		gameModel->counter.player_one_score += 1;
		score = gameModel->counter.player_one_score;
	}
	else{
		gameModel->counter.player_two_score += 1;
		score = gameModel->counter.player_two_score;
	}
	
	return score;
}

int	update_health(model *gameModel, int playerNumber){
	int zeroHealth;
	
	if(playerNumber == 1){
		gameModel->p1_health.amount_of_health -= 1;
		if(gameModel->p1_health.amount_of_health == 0){
			zeroHealth = TRUE;
		}
	}
	else{
		gameModel->p2_health.amount_of_health -= 1;
		if(gameModel->p2_health.amount_of_health == 0){
			zeroHealth = TRUE;
		}
	}
	return zeroHealth;
} 


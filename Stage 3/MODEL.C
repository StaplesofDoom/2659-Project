#include "model.h"

/* Initializers */

void initialize_model(model *gameModel){
	gameModel->One.x = 25;
	gameModel->One.y = 25;
	gameModel->One.delta_x = 25;
	gameModel->One.delta_y = 25;
	gameModel->One.aim_angle = 45;
	gameModel->One.player_number = 1;

	gameModel->Two.x = 25;
	gameModel->Two.y = 25;
	gameModel->Two.delta_x = 25;
	gameModel->Two.delta_y = 25;
	gameModel->Two.aim_angle = 45;
	gameModel->Two.player_number = 2;
	
	gameModel->p1_health.x = 125;
	gameModel->p1_health.y = 125;
	gameModel->p1_health.amount_of_health = 3;
	gameModel->p1_health.player_number = 1;

	gameModel->p2_health.x = 250;
	gameModel->p2_health.y = 250;
	gameModel->p2_health.amount_of_health = 3;
	gameModel->p2_health.player_number = 2;

	gameModel->counter.x = 200;
	gameModel->counter.y = 200;
	gameModel->counter.player_one_score = 0;
	gameModel->counter.player_two_score = 0;

}

void initialize_collision_array(model *gameModel){
}
/* Behaviour functions */

float physics_calculator(model *gameModel){

	return 0;
}

int score(int playerNumber, scoreCounter *counter){

	return 0;
}

int check_collisions(){
	int collide;

	collide = TRUE;

	return collide;
}


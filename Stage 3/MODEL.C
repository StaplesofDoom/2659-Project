#include "model.h"

/* Initializers */

void initialize_tanks(model *gameModel){

	gameModel->One.x = 25;
/*	player_one->y = 25;
	player_one->delta_x = 25;
	player_one->delta_y = 25;
	player_one->aim_angle = 45;
	player_one->player_number = 1;

	player_two->x = 50;
	player_two->y = 50;
	player_two->delta_x = 50;
	player_two->delta_y = 50;
	player_two->aim_angle = 75;
	player_two->player_number = 2;
	*/
}
/*
void initialize_health(healthBar *player_one, healthBar *player_two){
	player_one->x = 125;
	player_one->y = 125;
	player_one->amount_of_health = 3;
	player_one->player_number = 1;

	player_two->x = 250;
	player_two->y = 250;
	player_two->amount_of_health = 3;
	player_two->player_number = 2;
}

void initialize_score(scoreCounter *counter){

	counter->x = 200;
	counter->y = 200;
	counter->player_one_score = 0;
	counter->player_two_score = 0;
}
*/
/* Behaviour functions */
/*
float physics_calculator(tankShell *shell, float angle, int time, float yKnotIn, float xKnotIn){

	int timeIn;
	float angle_percentage;
	float yKnot = yKnotIn;
	float xKnot = xKnotIn;
	
	angle_percentage = (angle / 100);
	printf("%f", angle_percentage);
	timeIn = time;
	
	yKnot = (yKnot - (time*GRAVITY));
	xKnot = (xKnot * angle_percentage); 
	
	putchar(' ');
	printf("%f", xKnot);
	putchar(' ');
	printf("%f", yKnot);
	putchar('\n');
	
	
	return yKnot;
}

void move_tank(tank *tankToMove){

	tankToMove->x += tankToMove->delta_x;

}

void move_turret(tank *tankToAim, int direction){

	if(direction == 1){
		tankToAim->aim_angle += 5; 
	}
	else{
		tankToAim->aim_angle -= 5;
	}
}

void move_shell(tankShell *shell){

}

tankShell create_shell(){

	tankShell shell;

	return shell;

}

void damage_tank(tank *tankToDamage){

}

int remove_health(healthBar *player_health){

	int health;
	
	player_health->amount_of_health -= 1;
	
	return player_health->amount_of_health;
}

int score(int playerNumber, scoreCounter *counter){

	if(playerNumber == 1){
		counter->player_one_score += 1;
		return counter->player_one_score;
	}
	else
		counter->player_two_score += 1;
		return counter->player_two_score;
}

int check_collisions(tank *tankCollide){
	int collide;

	collide = TRUE;

	return collide;
}

void make_collision_array(){
	
}
*/

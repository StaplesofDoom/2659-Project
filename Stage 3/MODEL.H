#ifndef MODEL_H
#define MODEL_H

#include <osbind.h>
#include <stdio.h>

#define	GRAVITY 10
#define MAX_HEALTH 3
#define TRUE 1
#define FALSE 0

typedef struct{			/* All generic x and y integers can */
	int x;				/* be assumed to be screen positions*/
	int y;				/* All other variables are self- 	*/
	int delta_x;		/* explanatory 						*/
	int delta_y;
	int health;
	float aim_angle;
	int player_number;
} tank;

typedef struct{
	float x_velocity;
	float y_velocity;
	int x;
	int y;
	int flight_angle;
	int on_screen;
}tankShell;

typedef struct{
	int player_one_score;
	int player_two_score;
	int x;
	int y;
}scoreCounter;

typedef struct{
	int x;
	int y;
}terrain;	

typedef struct{
	int x;
	int y;
	int amount_of_health;
	int player_number;
}healthBar;

typedef struct{
	int x;
	int y;
}playerIndicator;

typedef struct{
	tank One;
	tank Two;
	tankShell p1_shell;
	tankShell p2_shell;
	scoreCounter counter;
	healthBar p1_health;
	healthBar p2_health;
	terrain floor;
	playerIndicator p1_indicator;
	playerIndicator p2_indicator;
	int collisions[3][2];			/* 3 Objects are tracked, both tanks and the floor */ 
									/* with a pair of coordinates for each 			   */
}model;
	
	
/* Behavior Functions */
void move_tank(model *gameModel);
void move_turret(model *gameModel);
void move_shell(model *gameModel);
int update_score(model *gameModel, int playerNumber);
int	update_health(model *gameModel, int playerNumber); 
int check_collisions(model *gameModel, int x, int y);
float physics_calculator(model *gameModel);

/* Event Request Functions */
void request_tank_move();
void request_turret_move();
void request_fire();

/* Initializers */
void initialize_model(model *gameModel); 
void initialize_collision_array(model *gameModel);

#endif

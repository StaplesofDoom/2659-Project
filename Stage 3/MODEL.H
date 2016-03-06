#ifndef MODEL_H
#define MODEL_H

#include <osbind.h>
#include <stdio.h>

#define	GRAVITY 10
#define MAX_HEALTH 3
#define TRUE 1
#define FALSE 0

typedef struct{			/* All generic x and y integers can */
	int x;				/* be assumed to be screen positions */
	int y;				/* All other variables are self- */
	int delta_x;		/* explanatory */
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
	/* bitmap for player indicator here */
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
	
}model;
	
	
/* Behavior Functions */
float physics_calculator(model *gameModel);
void move_tank(int tankNumber, model *gameModel);
void move_turret(model *gameModel);
void move_shell(model *gameModel);
void tank_fire(model *gameModel);
void damage_tank(int tankNumber, model *gameModel);
int  remove_health(int tankNumber, model *gameModel);
int score();
int check_collisions(model *gameModel);


/* Initializers */
void initialize_tanks(model *gameModel);
void initialize_health(model *gameModel);
void initialize_score(model *gameModel); 
void initialize_collision_array(model *gameModel);

#endif

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

/* Behavior Functions */
float physics_calculator(tankShell *shell, float angle, int time, float yKnotIn, float xKnotIn);
void move_tank(tank *tankToMove);
void move_turret(tank *tankToAim, int direction);
void move_shell(tankShell *shell);
void tank_fire(tank *tankToFire);
tankShell create_shell();
void damage_tank(tank *tankToDamage);
int  remove_health(healthBar *player_health);
int score();
int check_collisions(tank *tankCollide);


/* Initializers */
void initialize_tanks(tank *player_one, tank *player_two);
void initialize_health(healthBar *player_one, healthBar *player_two);
void initialize_score(scoreCounter *counter);  

#endif

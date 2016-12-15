#ifndef MODEL_H
#define MODEL_H

#define	GRAVITY 4
#define MAX_HEALTH 3
#define TRUE 1
#define FALSE 0
#define SHELL_VELOCITY 16

typedef struct{			/* All generic x and y integers can */
	unsigned int x;				/* be assumed to be screen positions*/
	unsigned int y;
	unsigned int old_x;
	unsigned int old_y;
	char direction;		/* All other variables are self- 	*/
	int delta_x;		/* explanatory 						*/
	int delta_y;
	int health;
	float aim_angle;
} tank;

typedef struct{
	int x_velocity;
	int y_velocity;
	unsigned int x;
	unsigned int y;
	unsigned int old_x;
	unsigned int old_y;
	int flight_angle;
	int on_screen;
}tankShell;

typedef struct{
	int player_one_score;
	int player_two_score;
	unsigned int x;
	unsigned int y;
}scoreCounter;

typedef struct{
	unsigned int x;
	unsigned int y;
}terrain;	

typedef struct{
	unsigned int x;
	unsigned int y;
	int amount_of_health;
}healthBar;

typedef struct{
	unsigned int x;
	unsigned int y;
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
void move_tank(model *gameModel,char direction, int playerNumber);
void move_turret(model *gameModel, int playerNumber, char direction);
void move_shell(model *gameModel,int playerNumber);
int update_score(model *gameModel, int playerNumber);
int	update_health(model *gameModel, int playerNumber); 
int check_shell_collisions(model *gameModel,int playerNumber);
int check_tank_collisions(model *gameModel,int playerNumber);
int physics_calculator(model *gameModel, int playerNumber);

/* Initializers */
void initialize_score(model *gameModel);
void initialize_model(model *gameModel); 
void initialize_shell(model *gameModel, int playerNumber);

#endif

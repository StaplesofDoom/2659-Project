#include "test_model.h"

int main(){

	int test;
	int time;
	char sent;
	float yKnot;

	tank One;
	tank Two;
	tankShell shell;
	scoreCounter counter;

	tank *Player1 = &One;
	tank *Player2 = &Two;
	tankShell *shellOne = &shell;
	
	scoreCounter *count = &counter;

	initialize_tanks(Player1, Player2);
	initialize_score(count);
	
	yKnot = 10;
	time = 1;
	sent = ' ';
	test = Player1->x;

	printf("%i", test);
	putchar('\n');

	test = count->x;

	printf("%i", test);
	putchar('\n');
	
	move_turret(Player1,1);
	
	test = Player1->aim_angle;
	
	printf("%i" , test);
	putchar('\n');
	
	move_turret(Player1, 0);
	
	test = Player1->aim_angle;
	
	printf("%i" , test);
	putchar('\n');
	
	printf("Working!");
	putchar('\n');
	
	while(sent != 'x'){
		scanf("%c", &sent);
		
		yKnot = physics_calculator(shellOne, 45, time, yKnot, 10);
		putchar('\n');
		time += 1;
		
	}
		
	return 0;
}

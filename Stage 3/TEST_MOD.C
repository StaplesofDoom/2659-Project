#include "TEST_MOD.H"

int main(){

	int test;
	model gameModel;
	model *game = &gameModel;
	initialize_tanks(game);
	
	test = game->One.x;
	
	printf("%i", test);
	putchar('\n');
	
	return 0;
}

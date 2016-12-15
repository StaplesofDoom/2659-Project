#ifndef EVENT_H
#define EVENT_H
#include "model.h"
#include "effects.h"


int request_tank_move(model *gameModel, int playerNumber);
int request_shell_move(model *gameModel, int playerNumber);
int request_turret_move(model *gameModel, int playerNumber, char direction);
int request_fire(model *gameModel, int playerNumber);
void ai_shot(model *gameModel);

#endif

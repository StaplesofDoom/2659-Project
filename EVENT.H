#ifndef EVENT_H
#define EVENT_H
#include "model.h"

void request_tank_move();
void request_turret_move();
void request_fire();

int check_hit();
int npc_fire();
void remove_shell();

#endif

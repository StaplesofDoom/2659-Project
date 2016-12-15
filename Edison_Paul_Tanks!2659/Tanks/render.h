#ifndef RENDER_H
#define RENDER_H

#include <osbind.h>

#include "model.h"
#include "raster.h"
#include "types.h"

#define W 1114231
#define A 1966177
#define S 2031731
#define D 2097252
#define SPACE 3735584
#define Q 1048689
#define ENTER 1835021
#define UP 0x480000
#define DOWN 0x500000

void out_screen(UINT8 *base, model *game);
void end_screen(UINT8 *base, model *game);
void update_tank(UINT8 *base, model *game);
void update_turret(UINT8 *base, model *game);
void update_shell(UINT8 *base, model *game);
void update_healthbar(UINT8 *base, model *game);

#endif
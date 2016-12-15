#ifndef MUSIC_H
#define MUSIC_H

#include "types.h"
#include "psg.h"

extern int music_notes[];
void start_music();
void update_music(UINT32 time_elapsed);



#endif
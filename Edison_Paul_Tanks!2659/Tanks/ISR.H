#ifndef ISR_H
#define ISR_H

#include "types.h"
#define VBL 28
#define IKBD 70
#define BUFFER_SIZE 256

extern int timer;
extern UINT8 render_request;

typedef void (*Vector)();
Vector install_vector(int num, Vector vector);

void vbl_isr();
void do_vbl_isr();
void IKBD_isr();
void do_IKBD_isr();
void enqueue(int in);
int dequeue();


#endif
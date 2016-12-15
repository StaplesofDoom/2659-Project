#include "isr.h"
#include <osbind.h>

/* This module is our ISR code, for installing our own ISRs into the ST. The module is
mostly game-independent, with a call to update_music being the only outside call.
Handles keyboard input, video blank calls and timing functions. Also include a small
chunk of Assembly code in ISRA.S.
 */


int input_buffer[BUFFER_SIZE], front = -1, rear = -1, state = 0, count = 0, buffer_empty = 0;

Vector install_vector(int num, Vector vector){
	Vector orig;
	Vector *vectp = (Vector *)((long)num << 2);
	long old_sp = Super(0);
	
	orig = *vectp;
	*vectp = vector;
	
	Super(old_sp);
	
	return orig;
}

void do_vbl_isr(){
	render_request += 1;		/*Sets the global render flag and increments the timer */
	timer += 1;
}

void do_IKBD_isr(){
	
	volatile char *ACIA_read = 0xFFFFFC02;
	volatile char *MFP = 0xFFFA11;
	int input;
	
	if(state == 0){								/*Initial state, most base input will be here */
		input = *ACIA_read;						/* Transitions to state 2 (Break code) or state 3(Mouse packets) */
		enqueue(input);
		if(input == 0xF9 || input == 0xFA){
			state = 3;
			count++;
		}
		else
			state = 1;
	}
	else if(state == 1){
		input = *ACIA_read;
		enqueue(input);
		state = 0;
	}
	else if(state == 3){
		input = *ACIA_read;
		enqueue(input);
		count++;
		if(count == 3){
			state = 0;
		}
	}
	
	*MFP = 0x00;		/* Resets the in-service bit of the MFP so that the ISR will go off again */
	
}

void enqueue(int in){

	if(rear == -1)
	{
		rear = 0;
		front = 0;
		buffer_empty = 0;
	}
	else if(rear == BUFFER_SIZE-1)
		rear = 0;
	else
		rear++;

	input_buffer[rear] = in;
	buffer_empty = 1;
 }


int dequeue(){
	
	int remove = input_buffer[front];

	if(front == rear)
		{
		front = -1;
		rear = -1;
		buffer_empty = 0;
		}
	else if(front == BUFFER_SIZE-1)
		front = 0;
	else
		front++;
	
	return remove;
}
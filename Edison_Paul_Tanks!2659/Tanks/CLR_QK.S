; Name: clr_qk
; Purpose: Clears the screen
		xdef		_clr_qk,_clr_full

base		equ		64		; offset from SP, not A6

; Name: clr_qk 
; Purpose: Clears the screen minus the ground that is initialized in set_area
_clr_qk:	movem.l		d0-7/a0-6,-(sp)
		lea		zeros,a0
		movem.l		(a0)+,d1-7/a1-6
		movea.l		base(sp),a0
		adda.l		#24000,a0
		move.w		#461,d0
		jmp			fill_loop

; Name: clr_qk 
; Purpose: Clears the whole screen		
_clr_full:	movem.l		d0-7/a0-6,-(sp)
		lea		zeros,a0
		movem.l		(a0)+,d1-7/a1-6
		movea.l		base(sp),a0
		adda.l		#32000,a0
		move.w		#614,d0

fill_loop:	movem.l		d1-7/a1-6,-(a0)
		dbra		d0,fill_loop
		movem.l		d1-7,-(a0)
		movem.l		(sp)+,d0-7/a0-6
		rts

zeros:		ds.l		13

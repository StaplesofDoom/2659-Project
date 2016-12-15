; Name: Set_area
; Purpose: Sets the ground.
		xdef		_set_area

base		equ		64		; offset from SP, not A6

_set_area:	movem.l		d0-7/a0-6,-(sp)
		lea		zeros,a0
		movem.l		(a0)+,d1-7/a1-6
		movea.l		base(sp),a0
		adda.l		#32000,a0
		move.w		#152,d0
fill_loop:	movem.l		d1-7/a1-6,-(a0)
		dbra		d0,fill_loop
		movem.l		d1-7/a1-4,-(a0)
		movem.l		(sp)+,d0-7/a0-6
		rts

zeros:		dc.l	$AA5AA5AA, $5AA5AA5A, $A5AA5AA5, $AA5AA5AA, $5AA5AA5A, $A5AA5AA5, $AA5AA5AA, $5AA5AA5A, $A5AA5AA5, $AA5AA5AA, $5AA5AA5A, $A5AA5AA5, $AA5AA5AA
; Name: Steem
; Purpose: gets the video base and also sets video base
	xdef		_get_video_base,_set_video_base
	
_get_video_base:
	move.l	d0,-(sp)
	
	clr.l	d0
		
	lea		$FFFF8201,a0
	movep.w	(a0),d0
	lsl.l	#$8,d0
	
	move.l	(sp)+,a0
	rts
	
_set_video_base:
	link	a6,#0
	movem.l	d0-2/a0-2,-(sp)
	
	move.l	8(a6),d0
	lsr.l	#8,d0
	lea		$FFFF8201,a0
	movep.w	d0,0(a0)
	
	movem.l	(sp)+,d0-2/a0-2
	unlk	a6
	rts
	
old_ssp:	ds.l	1
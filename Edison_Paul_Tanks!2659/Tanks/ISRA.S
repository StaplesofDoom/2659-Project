		xdef        _vbl_isr
		xdef		_IKBD_isr
        xref        _do_vbl_isr
		xref		_do_IKBD_isr

_vbl_isr:
			 movem.l  d0-d2/a0-a2,-(sp)
			 jsr     _do_vbl_isr
			 movem.l (sp)+,a0-a2/d0-d2
			 rte
			 
_IKBD_isr	
			 movem.l  d0-d2/a0-a2,-(sp)
			 jsr	_do_IKBD_isr
			 movem.l  (sp)+,a0-a2/d0-d2
			 rte
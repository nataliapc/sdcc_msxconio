#include "msx_const.h"
#include "conio.h"
#include "conio_aux.h"


/**
 * Gets the video information of the text mode. This information is stored
 * in a structure pointed to by the argument *ti. The text_info structure is
 * defined according to {@link text_info}
 */
void gettextinfo(text_info *ti)
{
	ti->winleft = _current_text_info.winleft;
	ti->wintop = _current_text_info.wintop;
	ti->winright = _current_text_info.winright;
	ti->winbottom = _current_text_info.winbottom;
	ti->attribute = _current_text_info.attribute;
	ti->normattr = _current_text_info.normattr;
	ti->currmode = _current_text_info.currmode;
	ti->screenheight = ADDR_POINTER_BYTE(CRTCNT);
	ti->screenwidth = ADDR_POINTER_BYTE(LINLEN);
	ti->curx = wherex();
	ti->cury = wherey();
}

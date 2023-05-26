#ifndef SWXBaseUiEnums_H
#define SWXBaseUiEnums_H

const unsigned int SWXUiStyleCommandPanel	  = 0x0001;
const unsigned int SWXUiStyleCommandManager	= 0x0002;
const unsigned int SWXUiStyleToolbar				= 0x0004;
const unsigned int SWXUiStyleGrid						=	0x0008;
const unsigned int SWXUiStyleContextMenu		=	0x0010;
const unsigned int SWXUiStyleImmersivePopup		=	0x0020;
const unsigned int SWXUiStyleContextMenuAlter		=	0x0021;
const unsigned int SWXUiStyleSTOP		=	0x0080; // stop recursion and consider this the top level.

enum SWXUiNotifyMode
{
	SWXUiNotifyMode_Apply,
	SWXUiNotifyMode_Keyboard, // incomplete keyboard entry
	SWXUiNotifyMode_Drag, // drag a handle etc.
	SWXUiNotifyMode_MouseMove, // mouse move to a point with button up, i.e. like drag but not dragging
	SWXUiNotifyMode_MouseMoveWithoutApply, // mouse move to a point with button up, i.e. like drag but not dragging
	SWXUiNotifyMode_MouseOver, // mouse over a control
	SWXUiNotifyMode_PreValued, // pre-selection mouse over
	SWXUiNotifyMode_MouseLeave // mouse leave the button
};


#endif

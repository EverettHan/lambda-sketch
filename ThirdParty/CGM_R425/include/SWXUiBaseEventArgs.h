//===================================================================
// COPYRIGHT DS SolidWorks Corporation 2012/06/20
//===================================================================
// SWXUiBaseEventArgs.cpp
// Header definition of class SWXUiBaseEventArgs
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2012/06/20 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef SWXUiBaseEventArgs_H
#define SWXUiBaseEventArgs_H

#include "SWXUtBasePacket.h"
#include "CATBaseUnknown.h"

class SWXUiIxComponent;
class CATVidWidget;

//-----------------------------------------------------------------------
class ExportedBySWXUtBasePacket SWXUiBaseEventArgs: public CATBaseUnknown
{
public:
	SWXUiBaseEventArgs (SWXUiIxComponent* iSrcComp, CATVidWidget* iSrcWidget, CATBaseUnknown* iEvtArgs=0, void* iCustomData = NULL);
	virtual ~SWXUiBaseEventArgs ();

	SWXUiIxComponent* GetEventSourceComp();
	CATVidWidget*			GetEventSourceWidget();
	CATBaseUnknown*   GetSourceEventArgs();
	void*							GetCustomData();

private:
	SWXUiIxComponent* mEventSourceComp;
	CATVidWidget*			mEventSourceWidget;
	CATBaseUnknown*   mEventArgs;
	void*             mCustomData;

private:
	SWXUiBaseEventArgs (SWXUiBaseEventArgs &);
	SWXUiBaseEventArgs& operator=(SWXUiBaseEventArgs&);

};

//-----------------------------------------------------------------------

#endif
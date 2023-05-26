//===================================================================
// COPYRIGHT Microsoft 2011/03/07
//===================================================================
// CATSWXVisu2DIndicator.cpp
// Header definition of class CATSWXVisu2DIndicator
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2011/03/07 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATSWXVisu2DIndicator_H
#define CATSWXVisu2DIndicator_H

#include "CATVisFoundation.h"
#include "CAT2DIndicator.h"

class CATVizViewer;
class CATSWXVisu2DViewpointEditor;
class CATNotification;

//-----------------------------------------------------------------------

class ExportedByCATVisFoundation CATSWXVisu2DIndicator: public CAT2DIndicator
{
	CATDeclareClass;

public:

	CATSWXVisu2DIndicator(CATVizViewer *iFather, const CATString &iName, CAT2DViewpoint &iViewpoint, CATSWXVisu2DViewpointEditor* iEditor);
	virtual ~CATSWXVisu2DIndicator ();

	void InternalDeviceEventCB( CATCallbackEvent ie, void *, CATNotification *iEvent, CATSubscriberData is, CATCallback icb);
	void ViewpointEditorSetCallback(CATCallbackEvent   iPublishedEvent, void* iPublishingObject, CATNotification* iNotification,
					              CATSubscriberData iClientData, CATCallback iCallback);	

private:
	// Copy constructor and equal operator
	// -----------------------------------
	CATSWXVisu2DIndicator (CATSWXVisu2DIndicator &);
	CATSWXVisu2DIndicator& operator=(CATSWXVisu2DIndicator&);

	HRESULT ZoomOnWheel(CATNotification* iEvent);

	CATSWXVisu2DViewpointEditor* mViewpointEditor;

	CATVizViewer* mVizViewer;
	CATCallback mVizCallback;
	CATCallback mMouseCB;

};

//-----------------------------------------------------------------------

#endif

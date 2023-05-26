//===================================================================
// COPYRIGHT [!output company] 2010/08/09
//===================================================================
// SWXIAppNotificationHandler.cpp
// Header definition of class SWXIAppNotificationHandler
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2010/08/09 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef SWXIAppNotificationHandler_H
#define SWXIAppNotificationHandler_H

#include "SWXUtGeneral.h"
#include "CATBaseUnknown.h"


extern ExportedBySWXUtGeneral  IID IID_SWXIAppNotificationHandler ;


class ExportedBySWXUtGeneral SWXIAppNotificationHandler: public CATBaseUnknown
{
	CATDeclareInterface;

public:

	virtual HRESULT NotificationFired() = 0;

};

//-----------------------------------------------------------------------
CATDeclareHandler( SWXIAppNotificationHandler, CATBaseUnknown );

#endif

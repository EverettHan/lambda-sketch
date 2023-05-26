// COPYRIGHT Dassault Systemes 2004
#ifndef CATIDropViewController_H
#define CATIDropViewController_H

#include <CATViewItf.h>
#include <CATBaseUnknown.h>

extern ExportedByCATViewItf IID IID_CATIDropViewController;

class CATNotification;

/**
 * Methods for support of drag&drop by controllers
 **/
class ExportedByCATViewItf CATIDropViewController: public CATBaseUnknown
{
	CATDeclareInterface;
public:
	virtual void OnBeginPreDrop( CATNotification *iNotification ) = 0;
	virtual void OnPreDrop( CATNotification *iNotification ) = 0;
	virtual void OnEndPreDrop( CATNotification *iNotification ) = 0;
	virtual void OnDrop( CATNotification *iNotification ) = 0;
};

CATDeclareHandler( CATIDropViewController, CATBaseUnknown );

#endif

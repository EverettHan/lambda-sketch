// COPYRIGHT Dassault Systemes 2004
#ifndef CATIViewModel_H
#define CATIViewModel_H

#include <CATAfrItf.h>
#include <CATEventSubscriber.h>

extern ExportedByCATAfrItf IID IID_CATIViewModel;

/**
 * CATIViewModel. Interface to display a model in a view.
 * CATViewModel is a default adapter that can be used to implement
 * this interface with no code.
 **/
class ExportedByCATAfrItf CATIViewModel: public CATBaseUnknown
{
	CATDeclareInterface;
public:
	/**
	 * Method called by views to register to model update event.
	 **/
	virtual CATCallback RegisterUpdateEvent( CATEventSubscriber *iSubscriber,
											CATSubscriberMethod iMethod,
											CATSubscriberData iData )= 0;
	/**
	 * Methode called by views to unregister to model update event
	 **/
	virtual void UnRegisterUpdateEvent( CATEventSubscriber *iSubscriber,
											CATCallback iUpdateCallback )= 0;
};

CATDeclareHandler(CATIViewModel, CATBaseUnknown);

#endif

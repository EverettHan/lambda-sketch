// COPYRIGHT Dassault Systemes 2004
#ifndef CATIPLMCompassLabel2_H
#define CATIPLMCompassLabel2_H

#include <CATAfrItf.h>
#include <CATIPLMCompassLabel.h>
#include <CATEventSubscriber.h>

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATIPLMCompassLabel2;
#else
extern "C" const IID IID_CATIPLMCompassLabel2 ;
#endif

/**
 */
class ExportedByCATAfrItf CATIPLMCompassLabel2: public CATIPLMCompassLabel
{
	CATDeclareInterface;
public:
	/**
	 * Get visibility: 0, object hidden; 1, object shown
	 **/
	virtual int GetVisibility( void ) = 0;
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

CATDeclareHandler( CATIPLMCompassLabel2, CATIPLMCompassLabel );

#endif

#ifndef _CATIPLMCompassFetcher_H
#define _CATIPLMCompassFetcher_H

#include <CATBaseUnknown.h>
#include <CATEventSubscriber.h>
#include <CATPLMCompassStyle.h>
#include "CATAfrItf.h"

extern ExportedByCATAfrItf IID IID_CATIPLMCompassFetcher;

/**
 * Interface to be implented by compass filters to control the 'player' area of the PLM Compass
 **/
class ExportedByCATAfrItf CATIPLMCompassFetcher : public CATBaseUnknown
{
	CATDeclareInterface;
public:
	/**
	 * The user has click on Back
	 **/
	virtual void OnBack( void ) = 0;
	/**
	 * The user has click on Next
	 **/
	virtual void OnNext( void ) = 0;
	/**
	 * The user has click on First
	 **/
	virtual void OnFirst( void ) = 0;
	/**
	 * The user has click on Last
	 **/
	virtual void OnLast( void ) = 0;
	/**
	 * The user has moved the slider.
	 * iPosition is the new position.
	 * GetPosition will be called by the compass to get the modified position
	 * => implementation can constraint the position this way.
	 **/
	virtual void OnSlider( int iPage ) = 0;
	/**
	 * Method called by the compass to get current slider position
	 **/
	virtual int GetCurrentPage( void ) = 0;
	/**
	 * Method called by the compass to get the total number of pages
	 **/
	virtual int GetPageCount( void ) = 0;
	/**
	 * Method called by the compass to register on position change event
	 **/
	virtual CATCallback RegisterUpdateEvent( CATEventSubscriber *iSubscriber,
											CATSubscriberMethod iMethod,
											CATSubscriberData iData )= 0;
	/**
	 * Methode called by views to unregister on play progress
	 **/
	virtual void UnRegisterUpdateEvent( CATEventSubscriber *iSubscriber,
											CATCallback iUpdateCallback )= 0;
};

CATDeclareHandler( CATIPLMCompassFetcher, CATBaseUnknown );

#endif

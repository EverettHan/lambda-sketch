// COPYRIGHT Dassault Systemes 2004
#ifndef CATViewModel_H
#define CATViewModel_H

#include <CATView.h>
#include <CATCallbackManager.h>

/**
 * Base class for view models.
 **/
class ExportedByCATView CATViewModel: public CATCallbackManager
{
	CATDeclareClass;
public:
	/**
	 * Constructor
	 **/
	CATViewModel( void );
	/**
	 * Destructor
	 **/
	virtual ~CATViewModel( void );
	/**
	 * CATIViewModel
	 **/
	virtual CATCallback RegisterUpdateEvent( CATEventSubscriber *iSubscriber,
											CATSubscriberMethod iMethod,
											CATSubscriberData iData );
	virtual void UnRegisterUpdateEvent( CATEventSubscriber *iSubscriber,
											CATCallback iUpdateCallback );
	/**
	 * Ask for update of views from model change
	 **/
	HRESULT Update(void);
private:

	CATDefineCBEvent( UpdateNeeded )
};

#endif

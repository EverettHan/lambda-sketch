/* -*-c++-*- */
#ifndef CATISPECEVENTS_H
#define CATISPECEVENTS_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/** 
* @level Private
* @usage U3
*/
 

#include "CATInterfaceEvents.h"
class CATISpecEvents_var;


#include "AD0XXBAS.h"
extern ExportedByAD0XXBAS IID IID_CATISpecEvents ;

/**
* Interface to subscribe to features events management.
* <b> Note : </b> everybody is allowed to subscribe to those events,but it is prohibited to re-emit them.
*/

class ExportedByAD0XXBAS CATISpecEvents : public CATInterfaceEvents
{
  CATDeclareInterface;
  public:
  
  /**
   * Returns notification of features creation in the feature modeler.
   */
  virtual CATCallbackEvent GetCreationNotification() = 0 ;

  /**
   * Returns notification of features deletion in the feature modeler.
   */
  virtual CATCallbackEvent GetDeleteNotification() = 0 ;
	
  /**
  * @nodoc
  */
  virtual CATCallbackEvent GetCompoNotification() = 0 ;
  /**
  * Returns notification of feature's data modification ( name, userId ).
  */
  virtual CATCallbackEvent GetCompoValNotification() = 0 ;
  /**
  * @nodoc
  */
  virtual CATCallbackEvent GetCompoStructNotification() = 0 ;
  /**
  * @nodoc
  */
  virtual CATCallbackEvent GetCompoStructAddNotification() = 0 ;
  /**
  * @nodoc
  */
  virtual CATCallbackEvent GetCompoStructRemoveNotification() = 0 ;
  /**
  * Returns notification of feature's synchronisation.
  */
  virtual CATCallbackEvent GetAttrNotification() = 0 ;
  /**
  * Returns notification of add/remove of attributes on a feature.
  */
  virtual CATCallbackEvent GetAttrStructNotification() = 0 ;
  /**
  * @nodoc
  */
  virtual CATCallbackEvent GetAttrStructAddNotification() = 0 ;
  /**
  * @nodoc
  */
  virtual CATCallbackEvent GetAttrStructRemoveNotification() = 0 ;
  /**
  * Returns notification of attribute's value modification.
  */
  virtual CATCallbackEvent GetAttrValNotification() = 0 ;

/**
* @nodoc
* Provides easy unsuscription.
*/
  virtual void             UnSubscribeToAllEventsFrom(const CATISpecEvents_var& iSpec) = 0;
  
} ;


CATDeclareHandler( CATISpecEvents, CATInterfaceEvents ) ;


#endif
